#include <iostream>
#include "Rollable.hpp"
#include "Dice.hpp"
#include "ThreeDicePool.hpp"

double expected_value(Rollable& r, unsigned num = 1000) {
    unsigned long summ = 0;
    for (unsigned cnt = 0; cnt != num; ++cnt) {
        summ += r.roll();
    }
    return static_cast<double>(summ) / static_cast<double>(num);
}


int main() {
    // Тестирование Dice
    Dice d(6, 40);
    std::cout << "Dice expectation: " << expected_value(d, 100000) << std::endl;

    // Тестирование ThreeDicePool
    ThreeDicePool tdp(6, 1, 2, 3);
    std::cout << "ThreeDicePool expectation: " << expected_value(tdp, 100000) << std::endl;


    return 0;
}