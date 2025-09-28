#pragma once
#include "Rollable.hpp"
#include <memory>

class PenaltyDice : public Rollable {
public:
    PenaltyDice(std::unique_ptr<Rollable> dice);
    unsigned roll() override;
    ~PenaltyDice() override;
private:
    std::unique_ptr<Rollable> baseDice;
};