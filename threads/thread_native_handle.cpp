#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello, Thread!";
}

int main() {
    std::thread thr(hello);

    std::cout << "The native handle is: " << thr.native_handle() << "\n";

    thr.join();

    std::cout << "The native handle now is: " << thr.native_handle() << "\n";
}   