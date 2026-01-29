#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Elements of vector: ";
    for (auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    int n;
    std::cin >> n;

    std::cout << "Number of elements divisible by " << n << " using lambda expressions: \n";

    // I'm trying out multiple ways to use lambda expressions

    int cnt = std::count_if(vec.begin(), vec.end(), 
        [n] (int x) {
            return (x % n == 0);
        }
    );

    auto count_div = [vec] (int n) {
        return std::count_if(vec.begin(), vec.end(), 
            [n] (int x) {
                return (x % n == 0);
            }
        );
    };

    int cnt_div = [vec] (int n) {
        return std::count_if(vec.begin(), vec.end(), 
            [n] (int x) {
                return (x % n == 0);
            }
        );
    }(n);

    std::cout << cnt << "\n";
    std::cout << count_div(n) << "\n";
    std::cout << cnt_div << "\n";
}