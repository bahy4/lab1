#pragma once
#include "Rollable.hpp"
#include "Dice.hpp"

class ThreeDicePool : public Rollable{
public:
    ThreeDicePool(unsigned max, 
                  unsigned seed_1, 
                  unsigned seed_2, 
                  unsigned seed_3);
    unsigned roll() override;
    ~ThreeDicePool() override;

private:
    Dice d1, d2, d3;
};