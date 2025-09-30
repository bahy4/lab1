#pragma once
#include "Rollable.hpp"
#include <memory>

class PenaltyDice : public virtual Rollable {
public:
    PenaltyDice(std::unique_ptr<Rollable> dice);
    unsigned roll() override;
    virtual ~PenaltyDice() override;
    PenaltyDice() = default;
protected:
    std::unique_ptr<Rollable> baseDice;
};