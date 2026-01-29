#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello, Thread!";
}

int main() {
    std::thread thr(hello);

    thr.join();
}