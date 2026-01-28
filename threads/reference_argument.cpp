#include <iostream>
#include <thread>
#include <functional>

void addTen(int& x) {
    for (int i = 0; i < 10; i++) {
        x++;
    }
}

int main() {
    int number = 0;

    std::thread t(addTen, std::ref(number));
    t.join();

    std::cout << "number = " << number << "\n";  // 10
}
