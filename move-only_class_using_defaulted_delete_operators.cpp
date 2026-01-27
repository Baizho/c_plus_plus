#include <utility>

class Test {
    public:
        // delete makes function exist but cannot be called
        Test(const Test& test) = delete;
        Test& operator =(const Test&) = delete;

        // default means the compiler will synthesize default version of operator, lazy way of writing code ;/
        Test(Test&&) noexcept = default;
        Test& operator =(Test&&) noexcept = default;

        Test() = default;
};

// also important piece of info:
class A {
    public:
        A(const A&) = delete;
};

class B {
    public:
        A a;
        B(const B&) = default;  // error because A isn't copyable so C++ can't use default copy
};


int main() {
    Test t1, t2, t3;

    // Test t4(t1);  // compiler error
    // t2 = t1; // compiler error

    Test t4(std::move(t1)); // valid
    t3 = std::move(t2); // valid
}