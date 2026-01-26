#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{4, 2, 3, 5, 1};

    for (auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    for (auto& x : vec) {
        x += 2;
    }

    for (auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    
    return 0;
}