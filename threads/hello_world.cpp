#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello, World!";
}

int main() {
    std::thread thr(hello);

    thr.join();
}