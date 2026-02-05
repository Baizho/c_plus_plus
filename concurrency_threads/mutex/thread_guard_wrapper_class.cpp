#include <iostream>
#include <thread>

class thread_guard {
    std::thread thr;
    public:
    
        explicit thread_guard(std::thread&& thr) : thr(std::move(thr)) {

        }

        ~thread_guard() {
            if(thr.joinable()) {
                thr.join();
            }
        }

        thread_guard(const thread_guard&) = delete;
        thread_guard& operator=(const thread_guard&) = delete;
};

void hello() {
    std::cout << "Hello Thread!\n";
}

int main() {

    // thread_guard destructor is called first
    // calls join() so the program waits for the executation thread to finish
    // so thread_guard executation thread is destroyed
    // destructor doesnt call terminate()
    try {
        std::thread thr(hello);
        thread_guard thrguard(std::move(thr));

        // thread_guard thrguard(std::thread(hello))

        throw std::exception();
    } 
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
}