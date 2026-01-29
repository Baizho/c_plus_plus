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

int main() {

    // you can handles exceptions in its thread only
    std::cout << "Starting thread...\n";
    std::thread thread(hello);

    thread.join();

    std::cout << "it works";

    // unlike the below which wont catch it, uncaught exception, terminates everything
    std::cout << "Starting thread again...\n";
    try {
        std::thread thread(bye);

        thread.join();
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

}