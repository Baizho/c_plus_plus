#include <iostream>
#include <thread>

using namespace std::literals;

void hello() {
    std::this_thread::sleep_for(3s);

    std::cout << "Hello thread ID: " << std::this_thread::get_id() << "\n";
}

std::thread func() {
    std::thread thread(hello);
    std::cout << "Thread ID " << thread.get_id() << " was created and returned\n";

    return thread;
    // return std::thread(hello);
}

int main() {
    std::cout << "Starting thread...\n";
    std::thread thread = func();
    
    std::cout << "Thread ID " << thread.get_id() << " was received\n";
    thread.join();
}