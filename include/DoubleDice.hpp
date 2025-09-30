#pragma once
#include "BonusDice.hpp"
#include "PenaltyDice.hpp"
#include "Rollable.hpp"
#include <memory>

/*//DoubleDice без наследования
class DoubleDice : public Rollable{
public:
    DoubleDice(std::unique_ptr<Rollable> dice);
    unsigned roll() override;
    ~DoubleDice() override;
private:
    std::unique_ptr<Rollable> baseDice;
};*/

//DoubleDice с наследованием
class DoubleDice: public BonusDice, public PenaltyDice{
public:
    DoubleDice(std::unique_ptr<Rollable> dice);
    unsigned roll() override;
    DoubleDice() : PenaltyDice(), BonusDice() {}
    ~DoubleDice() override;
private:
    std::unique_ptr<Rollable> baseDice;
}; 