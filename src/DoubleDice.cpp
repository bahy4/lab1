#include "Dice.hpp"
#include "DoubleDice.hpp"
#include "BonusDice.hpp"
#include "PenaltyDice.hpp"
#include "Rollable.hpp"
#include <memory>
#include <utility>

DoubleDice::DoubleDice(std::unique_ptr<Rollable> dice){
    PenaltyDice::baseDice = std::make_unique<Dice>(*dynamic_cast<Dice*>(dice.get()));
    BonusDice::baseDice = std::move(dice);
}

unsigned DoubleDice::roll(){
    return PenaltyDice::roll() + BonusDice::roll();
}

DoubleDice::~DoubleDice() = default;