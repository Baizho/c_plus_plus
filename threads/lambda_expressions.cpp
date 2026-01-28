#include <iostream>
#include <thread>

int main() {
    std::thread thr([]() {
        std::cout << "Hello Thread!";
    });

    thr.join();
}