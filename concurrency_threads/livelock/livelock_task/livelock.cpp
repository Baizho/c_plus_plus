#include <thread>
#include <iostream>

int x{0};

void func() {
    // this is dangerous and can probably have a data race, fix with a guard template
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

