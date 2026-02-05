#ifndef SINGLETON_H // (Classic Singleton implementation)
#define SINGLETON_H

#include <iostream>

// Classic Singleton class implementation 
class Singleton {
    static Singleton* single;

    // make constructor private so people can't create objects (abuse)
    Singleton() {
        std::cout << "Initializing Singleton...\n";
    }

    public:
        // remove copy and move capabilities
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton&& operator=(Singleton&&) = delete;

        // Static member function to obtain the Singleton object
        static Singleton* get_Singleton();
};

#endif