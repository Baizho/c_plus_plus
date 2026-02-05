#include "cpp11_singleton.h"
// Singleton class implementation (Meyers Singleton)
// Uses C++11's guarantees about initializing static variables

Singleton& get_Singleton() {
    static Singleton single;
    return single;
}