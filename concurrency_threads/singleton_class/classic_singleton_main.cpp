#include "classic_singleton.h"

#include <iostream>
#include <vector>
#include <thread>

Singleton* Singleton::single = nullptr;

void task() {
    Singleton* single = Singleton::get_Singleton();
    std::cout << single << "\n";
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i ++) {
        threads.push_back(std::thread(task));
    }

    for (std::thread& thread : threads) {
        thread.join();
    }
}