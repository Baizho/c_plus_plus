// Lazy initialization (single-threaded)
#include <iostream>

class Test {
	// ...
public:
	void func() { std::cout << "Function used\n";}
};

Test* ptest = nullptr;          // Variable to be lazily initialized

void process() {
    if (!ptest)                // First time variable has been used
        ptest = new Test;      // Initialize it
    ptest->func();             // Use it
    std::cout << ptest << "\n";
}


int main() {
    process();
}