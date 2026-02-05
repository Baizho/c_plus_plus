/*
A group of children sit in a circle, counting numbers out loud.

The first child says "one", the next child says "two", the next child says "three", and so on.

However, if the number is divisible by 3, they say "fizz" instead of the number. 
If the number is divisible by 5, they say "buzz", and if the number is divisible by 3 and by 5, they say "fizzbuzz".

Implement the game and then launch the game in a seperate thread
*/

#include <iostream>
#include <thread>
#include <string>

const int nplayers{4};
const int nturns{30};
std::string player_names[] = {"Abdul", "Bart", "Claudia", "Divya"};

void fizzbuzz(int nturns, int nplayers, std::string names[]) {
    // std::cout << "Worker thread id: " << std::this_thread::get_id() << "\n";

    for (int i = 1; i <= nturns; i++) {
        std::cout << names[(i-1)%nplayers] << " ";

        if (i % 15 == 0) std::cout << "fizzbuzz\n";
        else if (i % 3 == 0) std::cout << "fizz\n";
        else if (i % 5 == 0) std::cout << "buzz\n";
        else std::cout << i << "\n";
    }
}


int main() {
    // std::cout << "Main thread id: " << std::this_thread::get_id() << "\n";

    std::thread game(fizzbuzz, nturns, nplayers, player_names);

    game.join();
}