#include <cmath>
#include <ios>
#include <iostream>
#include "Rollable.hpp"
#include "Dice.hpp"
#include "ThreeDicePool.hpp"
#include "PenaltyDice.hpp"
#include "BonusDice.hpp"
#include <memory>
#include <iomanip>
#include <vector>


double expected_value(Rollable& r, unsigned num = 10000) {
    unsigned long summ = 0;
    for (unsigned cnt = 0; cnt != num; ++cnt) {
        summ += r.roll();
    }
    return static_cast<double>(summ) / static_cast<double>(num);
}

double value_probability(unsigned value, Rollable& r, unsigned number_of_rolls = 10000) {
    unsigned count = 0;
    for (unsigned cnt = 0; cnt != number_of_rolls; ++cnt) {
        if (r.roll() == value) {
            ++count;
        }
    }
    return static_cast<double>(count) / static_cast<double>(number_of_rolls);
}

void print_histogram(Rollable& r, const std::string& name, unsigned minn, unsigned maxx, unsigned width, unsigned NUM=10000){
    std::cout<<"\nГистограмма для "<< name<<std::endl;
    double max_prob=0;
    std::pmr::vector<double> vec (maxx+1);
    for (unsigned i = minn; i<=maxx; ++i){
        vec[i]=value_probability(i, r,NUM);
        if (vec[i]>max_prob) max_prob=vec[i];
    }
    for (unsigned i = minn; i<=maxx; ++i){
        std::cout<<std::fixed<<std::setprecision(4)<<std::setw(4)<<i<<" "<<vec[i];
        for (unsigned j = 0; j<=std::round(width*vec[i]/max_prob); ++j){
            std::cout<<"=";
        }
        std::cout<<"\n";
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int NUM = 1000000;
    Dice d100(100,2);
    PenaltyDice pen100(std::make_unique<Dice>(100,3));
    BonusDice bon100(std::make_unique<Dice>(100,4));
    ThreeDicePool tdp(std::make_unique<Dice>(6,5),std::make_unique<Dice>(6,10),std::make_unique<Dice>(6,7));
    BonusDice bontdp(std::make_unique<ThreeDicePool>(std::make_unique<Dice>(6,5),std::make_unique<Dice>(6,10),std::make_unique<Dice>(6,7)));
    PenaltyDice pentdp(std::make_unique<ThreeDicePool>(std::make_unique<Dice>(6,5),std::make_unique<Dice>(6,10),std::make_unique<Dice>(6,7)));
    std::cout << "Dice(100) expectation: " << expected_value(d100, NUM) << std::endl;
    //std::cout << "PenaltyDice(100) expectation: " << expected_value(pen100, NUM) << std::endl;
    std::cout << "BonusDice(100) expectation: " << expected_value(bon100, NUM) << std::endl;
    print_histogram(d100, "Обычный бросок d100", 1, 100,60,NUM);
    print_histogram(bon100, "Бросок d100 с приемуществом", 1, 100,60,NUM);
    print_histogram(pen100, "Бросок d100 с помехой", 1, 100,60,NUM);
    print_histogram(tdp, "Обычный бросок 3 d6", 3, 18, 60,NUM);
    print_histogram(bontdp, "Бросок 3d6 с приемуществом", 3, 18, 60,NUM);
    print_histogram(pentdp, "Бросок 3d6 с помехой", 3, 18, 60,NUM);
    return 0;
}