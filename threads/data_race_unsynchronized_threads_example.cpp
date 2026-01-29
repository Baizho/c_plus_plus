#include <iostream>
#include <thread>
#include <string>

void print(std::string str) {
    for (int i = 0; i < 3; ++ i) {
        // shared memory is from cout
        std::cout << str[0] << str[1] << str[2] << "\n";
    }
}

int main() {
    // Unsynchronized threads which make conflicting accesses
    std::thread t1(print, "abc");
    std::thread t2(print, "def");
    std::thread t3(print, "xyz");

    t1.join();
    t2.join();
    t3.join();
}