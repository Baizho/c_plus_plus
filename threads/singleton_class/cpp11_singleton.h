#ifndef SINGLETON_H // (Meyers Singleton)
#define SINGLETON_H

#include <iostream>

// Singleton class implementation (Meyers Singleton)
class Singleton {
    public: 
        // remove copy and move capabilities
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton&& operator=(Singleton&&) = delete;

        Singleton() {
            std::cout << "Initializing Singleton...\n";
        }
};

Singleton& get_Singleton();

#endif // SINGLETON_H