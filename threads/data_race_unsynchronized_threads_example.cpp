#include <iostream>
#include <thread>
#include <string>

void print(std::string str) {
    for (int i = 0; i < 3; ++ i) {
        // shared memory is from cout
        std::cout << str[0] << str[1] << str[2] << "\n";
    }
}

int counter = 0;

void increment() {
    for (int i = 0; i < 100000; ++ i) {
        counter += 1;
    }
}

int main() {
    // Unsynchronized threads which make conflicting accesses
    // threads get interrupted and continue
    std::thread t1(print, "abc");
    std::thread t2(print, "def");
    std::thread t3(print, "xyz");

    t1.join();
    t2.join();
    t3.join();

    // another example, but using global shared variable
    std::thread t4(increment);
    std::thread t5(increment);
    std::thread t6(increment);

    // here, of course we don't expect 300000
    std::cout << counter << "\n";

    t4.join();
    t5.join();
    t6.join();
    
    // here, we also don't get 300000 because of data race
    // some threads when resuming execution might not get latest information about counter
    std::cout << counter << "\n";

}