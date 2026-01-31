#include "cpp11_singleton.h"

#include <iostream>
#include <vector>
#include <thread>

void task() {
    Singleton& singleton = get_Singleton();
    std::cout << &singleton << "\n";
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
