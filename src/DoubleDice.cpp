#include "Dice.hpp"
#include "DoubleDice.hpp"
#include "BonusDice.hpp"
#include "PenaltyDice.hpp"
#include "Rollable.hpp"
#include <memory>
#include <utility>
#include <cmath>

/*//DoubleDice без наследования
DoubleDice::DoubleDice (std::unique_ptr<Rollable> dice)
    : baseDice(std::move(dice)){}

DoubleDice::~DoubleDice()=default;

unsigned DoubleDice::roll(){
    unsigned roll1 = baseDice->roll();
    unsigned roll2 = baseDice->roll();
    unsigned roll3 = baseDice->roll();
    unsigned roll4 = baseDice->roll();
    
    return fmax(roll1, roll2) + fmin(roll3, roll4);
}*/


//DoubleDice с наследованием
class SharedDiceWrapper : public Rollable {
public:
    SharedDiceWrapper(Rollable& dice) : refDice(dice) {}
    unsigned roll() override { return refDice.roll(); }
private:
    Rollable& refDice;
};

DoubleDice::DoubleDice(std::unique_ptr<Rollable> dice) 
    : PenaltyDice(nullptr), BonusDice(nullptr), baseDice(std::move(dice)) {
    
    PenaltyDice::baseDice = std::make_unique<SharedDiceWrapper>(*baseDice);
    BonusDice::baseDice = std::make_unique<SharedDiceWrapper>(*baseDice);
}

unsigned DoubleDice::roll(){
    return PenaltyDice::roll() + BonusDice::roll();
}

DoubleDice::~DoubleDice() = default;