// Fixed implementation of blocking queue (thread-safe)
#include <vector>
#include <list>
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <sstream>

// Thread-safe logging
std::mutex cout_mtx;

void log(const std::string& msg) {
	std::lock_guard<std::mutex> lock(cout_mtx);
	std::cout << msg << std::endl;
}

template <typename T>
struct LockFreeQueue {  // (Name kept same to preserve structure, but this is NOT lock-free)
private:
	// Use an std::list to store the elements
	std::list<T> lst;

	// iHead and iTail iterators
	typename std::list<T>::iterator iHead, iTail;

    // Synchronization primitives
    std::mutex mtx;
    std::condition_variable cv;

public:
	// Class constructor
	LockFreeQueue()
	{
		// Create a "dummy" element to separate iHead from iTail
		lst.push_back(T());
		iHead = lst.begin();
		iTail = lst.end();
	}

	// Producer thread function
	void Produce(const T& t)
	{
        std::unique_lock<std::mutex> lock(mtx);

		std::stringstream ss;
		ss << "Producer " << std::this_thread::get_id() << " pushing " << t;
		log(ss.str());

		// Add the new element
		lst.push_back(t);

		// Update iTail
		iTail = lst.end();

        // Notify a waiting consumer that data is available
        lock.unlock();  // unlock before notify (good practice)
        cv.notify_one();

		// Erase the removed elements (safe now because we hold the lock before unlock)
		lock.lock();
		lst.erase(lst.begin(), iHead);
	}

	// Consumer thread function
	bool Consume(T& t)
	{
        std::unique_lock<std::mutex> lock(mtx);

        // Wait until queue is not empty
        cv.wait(lock, [&]() {
            auto iFirst = iHead;
            ++iFirst;
            if (iFirst == iTail) {
                std::stringstream ss;
                ss << "Consumer " << std::this_thread::get_id() << " sleeping (queue empty)";
                log(ss.str());

                return false;
            }
            return true;
        });

		// Go to the first element
		auto iFirst = iHead;
		++iFirst;

		// If queue is not empty
		if (iFirst != iTail) {
			// Update iHead
			iHead = iFirst;

			// Fetch this first element
			t = *iHead;

			std::stringstream ss;
			ss << "Consumer " << std::this_thread::get_id() << " popped " << t;
			log(ss.str());

			return true;
		}

		// No elements to fetch (won’t normally happen due to wait)
		return false;
	}

	// Function to display all the elements
	void Print()
	{
        std::lock_guard<std::mutex> lock(mtx);

		// Go to the first element
		auto head = iHead;
		++head;

		std::cout << "Final queue contents: ";
		// We cannot use a range-for loop, because we only access some of the elements
		for (auto el = head; el != iTail; ++el)
			std::cout << *el << ", ";
		std::cout << '\n';
	}
}; // End of class definition

int main()
{
	LockFreeQueue<int> lfq;
	std::vector<std::thread> threads;
	int j = 1;

	for (int i = 0; i < 10; ++i) {
		// Run the member functions of LockFreeQueue in threads
		// Syntax for member function with std::thread:
		// First argument is a pointer to the member function
		// Second argument is the address of the object the member function is called on
		// (this will be the "this" pointer in the member function)
		// Then the arguments to the member function. These are passed as reference to int
		// so we need to wrap them in std::ref()

		std::thread produce(&LockFreeQueue<int>::Produce, &lfq, i);
		threads.push_back(std::move(produce));
		std::thread consume(&LockFreeQueue<int>::Consume, &lfq, std::ref(j));
		threads.push_back(std::move(consume));
	}

	// Wait for the threads to complete
	for (auto& thr: threads)
		thr.join();

	lfq.Print();
}
