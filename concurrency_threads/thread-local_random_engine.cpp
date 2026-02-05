#include <random>
#include <iostream>
#include <thread>

thread_local std::mt19937 mt;

void generate_random_numbers() {
    std::uniform_real_distribution<double> uid(0, 1);

    for (int i = 0; i < 5; i ++) {
        std::cout << uid(mt) << "\n";
    }
}

int main() {
    std::cout << "Thread 1's random numbers: \n";
    std::thread t1(generate_random_numbers);
    t1.join();

    
    std::cout << "Thread 2's random numbers: \n";
    std::thread t2(generate_random_numbers);
    t2.join();

    // they should generate the same random numbers since they have their own mt object
}