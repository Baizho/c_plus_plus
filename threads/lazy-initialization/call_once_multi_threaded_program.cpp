// Lazy initialization (multi-threaded)
// Uses std::call_once()
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

class Test {
	// ...
public:
    Test()
	{
		std::cout << "Test constructor called\n";
	}
	void func() { std::cout << "Function used\n";}
};

Test* ptest = nullptr;          // Variable to be lazily initialized

std::once_flag ptest_flag;         // The flag stores synchronization data

void process() {
    // Pass a callable object which performs the initialization
    std::call_once(ptest_flag, []() {
		ptest = new Test;
		}); // better than the Double-checked Locking algorithm
    ptest->func();
    std::cout << ptest << "\n";
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i ++) {
        threads.push_back(std::thread(process));
    }

    for (std::thread& thread : threads) {
        thread.join();
    }
}


