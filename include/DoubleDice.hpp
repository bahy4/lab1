#pragma once
#include "BonusDice.hpp"
#include "PenaltyDice.hpp"
#include "Rollable.hpp"
#include <memory>

class DoubleDice: public BonusDice, public PenaltyDice{
public:
    DoubleDice(std::unique_ptr<Rollable> dice);
    unsigned roll() override;
    DoubleDice() : PenaltyDice(), BonusDice() {}
    ~DoubleDice() override;
    
}; 