#include <iostream>
#include <random>

std::mt19937 mt;

int main() {
    std::cout << "5 random integers between 0 and 100\n";

    std::uniform_int_distribution<int> uid(0, 100);

    for (int i = 0; i < 5; ++i) {
        std::cout << uid(mt) << " ";
    }
    std::cout << "\n";

    std::cout << "\n";
    
    std::cout << "5 random floating-point numbers between 0 and 1\n";
    std::uniform_real_distribution<double> did(0, 1);

    for (int i = 0; i < 5; ++i) {
        std::cout << did(mt) << " ";
    }
    std::cout << "\n";
}