#include <iostream>
#include <vector>

void experiment_2(std::vector<int> v) {
    std::cout << "Inside the function, size of vector: " << v.size() << "\n";
}

std::vector<int> experiment_3(int n) {
    std::vector<int> v(n);
    return v;
}


int main() {
    // experiment 1, copy vs move with vectors
    std::cout << "Experiment 1, copy vs move with vectors\n";

    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Size of vec: " << vec.size() << "\n";

    std::vector<int> cpy = vec;
    std::cout << "After copy, size of vec: " << vec.size() << "\n";
    std::cout << "Size of cpy: " << cpy.size() << "\n";

    std::vector<int> mve = std::move(vec);
    std::cout << "After move, size of vec: " << vec.size() << "\n"; // should be 0
    std::cout << "Size of mve: " << mve.size() << "\n";

    std::cout << "\n";

    // experiment 2, moving instead of copying into functions
    std::cout << "Experiment 2, moving instead of copying into functions\n";

    vec = std::vector<int>(10000);

    std::cout << "Passing without move\n";
    experiment_2(vec);  // COPY
    std::cout << "Size of vec after copy: " << vec.size() << "\n";

    std::cout << "\n";

    std::cout << "Passing with move\n";
    experiment_2(std::move(vec));
    std::cout << "Size of vec after move: " << vec.size() << "\n";

    std::cout << "\n";

    // experiment 3, returning a big vector from function
    std::cout << "Experiment 3, returning a big vector from function\n";

    vec = experiment_3(100000);
    std::cout << "Size of recieved vector: " << vec.size() << "\n";
    std::cout << "Would've been slow in old C++, but it is now optimized because memory is moved, not copied\n";

    std::cout << "\n";

    // experiment 4, checking contents of vector after moving
    std::cout << "Experiment 4, checking contents of vector after moving\n";

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Size of vec: " << vec.size() << "\n";
    std::cout << "Elements of vec: ";
    for (auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    mve = std::move(vec);
    std::cout << "Size of vec after move: " << vec.size() << "\n";
    std::cout << "Elements of vec after move: ";
    for (auto x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Size of mve: " << mve.size() << "\n";
    std::cout << "Elements of mve: ";
    for (auto x : mve) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}