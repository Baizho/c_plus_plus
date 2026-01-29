#include <iostream>
#include <memory>

// unique_ptr<T> is a dynamically allocated object that is move-only (no copying allowed)
// it can be moved and automatically deletes the object when it goes out of scope (which we will test)
// usually you have to manually delete pointer "delete p;"

struct Point {
    int x, y;
};

int main() {
    auto uniq_ptr = std::make_unique<Point>(Point{3, 6});

    std::cout << uniq_ptr->x << " " << uniq_ptr->y << "\n";

    // auto p2 = uniq_ptr; // copying not allowed

    // it can be moved

    auto p2 = std::move(uniq_ptr);
    std::cout << p2->x << " " << p2->y << "\n";
}