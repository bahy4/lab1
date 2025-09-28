#include "BonusDice.hpp"

BonusDice::BonusDice(std::unique_ptr<Rollable> dice)
    : baseDice(std::move(dice)) {}

unsigned BonusDice::roll() {
    unsigned roll1 = baseDice->roll();
    unsigned roll2 = baseDice->roll();
    return std::max(roll1, roll2);
}

BonusDice::~BonusDice() = default;