#include <iostream>
#include <thread>

class Worker {
public:
    void doWork(int id) {
        std::cout << "Worker " << id << " running on thread " << std::this_thread::get_id() << "\n";
    }
};

void work(int& x) {
    x += 10;
}

int main() {
    Worker w;

    std::thread t(&Worker::doWork, &w, 1);
    //        ^ member fn ptr  ^ object  ^ argument

    t.join();

    // passing object and we don't want to copy it for optimal
    Worker w2;

    std::thread t2(&Worker::doWork, std::ref(w), 1);
    t2.join();

    // lambda
    Worker w3;

    std::thread t3([&w3]() {
        w3.doWork(1);
    });

    t3.join();


    // even if passed variable is reference, you always have to use the function
    
    int value = 10;
    int& ref = value;

    std::thread t4(work, std::ref(ref));  
    t4.join();
}
