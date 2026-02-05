#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello thread with ID: " << std::this_thread::get_id() << "\n";
}

int main() {
    std::cout << "Main thread has ID: " << std::this_thread::get_id() << "\n";

    std::thread thread1(hello);

    std::cout << "Launched thread with ID: " << thread1.get_id() << "\n";

    thread1.join();

    std::cout << "Finished thread with ID: " << thread1.get_id() << "\n";

}