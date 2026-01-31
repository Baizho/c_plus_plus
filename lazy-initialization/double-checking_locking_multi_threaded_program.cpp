// Lazy initialization (multi-threaded)
// Uses the Double-checked Locking algorithm
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
std::mutex mut;

void process() {
    if (!ptest) {                     // First check of ptest
        std::lock_guard<std::mutex> lck_guard(mut);
        
        if (!ptest)                  // Second check of ptest
            ptest = new Test;   // Initialize ptest
            // In C++14 or lower, this can still be dangerous because when initializing ptest, it has multiple operations:
            // 1. Allocate memory to store Test object
            // 2. store the address in ptest
            // 3. construct Test object in memory
            // there can be undefined behavior, thread B can use the not fully initialized object and undefined behaviour comes

            // In C++17, it is no longer dangerous or a data race
    }
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


