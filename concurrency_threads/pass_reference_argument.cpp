#include <iostream>
#include <thread>
#include <functional>

void addTen(int& x) {
    for (int i = 0; i < 10; i++) {
        x++;
    }
}

void printSize(const std::vector<int>& v) {
    std::cout << "Size: " << v.size() << "\n";
}

int main() {
    int number = 0;

    std::thread t(addTen, std::ref(number));
    t.join();

    std::cout << "number = " << number << "\n";  // 10

    std::vector<int> data(1'000'000, 1);

    std::thread t2(printSize, std::cref(data));  // no copy of 1M ints
    t2.join();
}
