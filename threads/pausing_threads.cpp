#include <iostream>
#include <thread>

using namespace std::literals;

void hello() {
    // make it sleep for 5 seconds
    std::this_thread::sleep_for(5s); // c++14 
    // std::this_thread::sleep_for(std::chrono::seconds(2)) // c++11
    std::cout << "Hello Thread!\n";
}

int main() {
    std::cout << "Starting thread...\n";
    std::thread thread(hello);

    thread.join();
}