// Lazy initialization (multi-threaded)
// Uses Meyers singleton
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

void process() {
    static Test ptest;            // Variable which is lazily initialized
	ptest.func();
    std::cout << &ptest << "\n";

    // very good
    // if ptest isn't required out of function, use meyers
    // otherwise use call_once
    // or you can use double-checked locking with c++17 compiler or later
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


