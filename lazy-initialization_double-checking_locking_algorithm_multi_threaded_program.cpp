// Lazy initialization (multi-threaded)
// Uses the Double-checked Locking algorithm
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
    if (!ptest) {                     // First check of ptest
        std::lock_guard<std::mutex> lck_guard(mut);
        
        if (!ptest)                  // Second check of ptest
            ptest = new Test;   // Initialize ptest
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


