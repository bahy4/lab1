#pragma once
#include<random>
#include "Rollable.hpp"

class Dice : public Rollable {
public:
    Dice(unsigned max, unsigned seed);
    unsigned roll() override;
    ~Dice() override;

private:
    unsigned max;
    std::uniform_int_distribution<unsigned> dstr;
    std::default_random_engine reng;
};