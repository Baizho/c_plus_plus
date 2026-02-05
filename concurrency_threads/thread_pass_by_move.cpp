#include <iostream>
#include <thread>

using namespace std::literals;

void hello() {
    std::this_thread::sleep_for(3s);

    std::cout << "Hello thread ID: " << std::this_thread::get_id() << "\n";
}

void func(std::thread&& thr) {
    std::cout << "Thread ID " << thr.get_id() << " was passed\n";

    // this is now responsible for it
    thr.join();
}

int main() {
    std::cout << "Starting thread...\n";
    std::thread thread(hello);

    // passing thread
    func(std::move(thread));

    // passing temporary object
    func(std::thread(hello));
}