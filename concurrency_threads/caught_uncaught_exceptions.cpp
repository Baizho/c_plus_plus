#include <iostream>
#include <thread>

using namespace std::literals;

void hello() {
    // make it sleep for 5 seconds
    std::this_thread::sleep_for(5s); // c++14 
    // std::this_thread::sleep_for(std::chrono::seconds(2)) // c++11

    try {
        throw std::exception();
    } 
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    std::cout << "Hello Thread!\n";
}

void bye() {
    throw std::exception();

    std::cout << "Goodbye Thread!\n";
}

void welcome() {
    std::cout << "Welcome Thread!\n";
}

int main() {

    // you can handles exceptions in its thread only
    std::cout << "Starting thread...\n";
    std::thread thread(hello);

    thread.join();

    // unlike the below which wont catch it, uncaught exception, terminates everything
    // std::cout << "Starting thread again...\n";
    // try {
    //     std::thread thread(bye);

    //     thread.join();
    // }
    // catch (std::exception& e) {
    //     std::cout << "Exception caught: " << e.what() << "\n";
    // }

    // another unsafe exception

    // std::cout << "Starting thread again...\n";
    // try {
    //     std::thread thread(welcome);

    //     throw std::exception();

    //     thread.join();
    // }
    // catch (std::exception& e) {
    //     std::cout << "Exception caught: " << e.what() << "\n";
    // }

    // safe exception to manage threads

    std::cout << "Starting thread again...\n";

    std::thread safethread(welcome);
    try {
        throw std::exception();

        safethread.join();
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";

        safethread.join();
    }

}