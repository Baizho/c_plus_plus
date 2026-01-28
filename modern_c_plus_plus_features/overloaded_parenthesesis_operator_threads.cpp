#include <iostream>
#include <thread>

class Hello {
    public:
        void operator()() {
            std::cout << "Hello Thread!";
        }
};

int main() {
    Hello obj;

    std::thread thr(obj);

    thr.join();
}