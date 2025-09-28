#include "PenaltyDice.hpp"

PenaltyDice::PenaltyDice(std::unique_ptr<Rollable> dice)
    : baseDice(std::move(dice)) {}

unsigned PenaltyDice::roll() {
    unsigned roll1 = baseDice->roll();
    unsigned roll2 = baseDice->roll();
    return std::min(roll1, roll2);
}
PenaltyDice::~PenaltyDice() = default;