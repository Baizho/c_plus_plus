#include <iostream>

class Test {};

void f(const Test& test) {
    std::cout << "lvalue reference!\n";
}

void f(Test&& test) {
    std::cout << "rvalue reference!\n";
}

int main() {
    Test a;

    f(a);
    f(Test());
    f(std::move(a));
}