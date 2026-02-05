#include <thread>
#include <iostream>
#include <mutex>

int x{0};

std::mutex func_mutex;

void func() {

    std::lock_guard<std::mutex> lck_guard(func_mutex);
    
    std::cout << "Starting thread: " << std::this_thread::get_id() << "\n";
    while (x == 0) {
        x = 1 - x;
    }
}

int main()
{
    std::thread thr1{ func };
    std::thread thr2{ func };
	
	thr1.join();
	thr2.join();
}

