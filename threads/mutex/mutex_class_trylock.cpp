#include <iostream>
#include <thread>
#include <mutex>

using namespace std::literals;

int class_size = 0;

std::mutex class_size_mutex;

void add_student() {
    std::cout << "Adding a student, trying to lock mutex\n";

    while(!class_size_mutex.try_lock()) {
        std::cout << "Adding a student, couldn't lock mutex\n";
        std::this_thread::sleep_for(1s);
    }

    std::cout << "Adding a student, locked the mutex\n";

    class_size += 1;
    std::this_thread::sleep_for(5s);

    std::cout << "Adding a student, unlocking the mutex\n";

    class_size_mutex.unlock();
}

void get_class_size() {
    std::cout << "Inquiring class size, trying to lock mutex\n";

    while(!class_size_mutex.try_lock()) {
        std::cout << "Inquiring class size, couldn't lock mutex\n";
        std::this_thread::sleep_for(1s);
    }

    std::cout << "Inquiring class size, locked the mutex\n";
    
    std::cout << "The class size is " << class_size << "\n";

    std::cout << "Inquiring class size, unlocking the mutex\n";

    class_size_mutex.unlock();
}

int main() {
    std::thread add_student_thread(add_student);
    std::thread get_class_size_thread(get_class_size);

    add_student_thread.join();
    get_class_size_thread.join();
}