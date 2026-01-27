#include <iostream>

int main() {
    // Variables which are local only to it's lambda body
    auto f = [y = 5] (int x) {
        return x * y;
    };

    std::cout << "Input number to be multiplied by 5\n";
    int n;
    std::cin >> n;

    std::cout << f(n) << "\n";

    std::cout << "\n";

    std::cout << "Input two numbers to multiply them\n";
    int a, b;
    std::cin >> a >> b;

    auto f1 = [y = a] (int x) {
        return x * y;
    };

    std::cout << f1(b) << "\n";
}