// Lazy initialization (multi-threaded)
// Inefficient (always locks the mutex)
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

class Test {
	// ...
public:
	void func() { std::cout << "Function used\n";}
};

Test* ptest = nullptr;          // Variable to be lazily initialized
std::mutex mut;

void process() {
    std::unique_lock<std::mutex> uniq_lck(mut);       // Protect ptest

    if (!ptest)
        ptest = new Test;
    uniq_lck.unlock();
    ptest->func();
    std::cout << ptest << "\n";
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; i ++) {
        threads.push_back(std::thread(process));
    }

    for (std::thread& thread : threads) {
        thread.join();
    }
}
