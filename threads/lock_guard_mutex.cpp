#include <iostream>
#include <thread>
#include <string>
#include <mutex>

using namespace std::literals;

std::mutex print_mutex;

void print(std::string str) {
    // we can lock the thread here if we want the whole thing to be in order
    // print_mutex.lock();
    for (int i = 0; i < 3; ++ i) {
        // shared memory is from cout 
        try {
            // if we don't do this, exception will be thrown and this wont unlock
            // if we don't unlock, we will try to lock again and that will throw an error
            std::lock_guard<std::mutex> lck_guard(print_mutex); 

            std::cout << str[0] << str[1] << str[2] << "\n";

            // critical section throws exception
            throw std::exception();
            // critical section ends

            std::this_thread::sleep_for(50ms);
        } // calls ~std::lock_guard
        catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << "\n";
        }
    }
    // print_mutex.unlock();
}

int counter = 0;

void increment() {
    // print_mutex.lock(); // we can lock it here if we want the whole thing to be in order
    for (int i = 0; i < 100000; ++ i) {
        std::lock_guard<std::mutex> lck_guard(print_mutex);

        counter += 1;
    }
    // print_mutex.unlock();
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
    
    // everything should be fine
    std::cout << counter << "\n";

}