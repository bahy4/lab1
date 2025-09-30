#pragma once
#include "Rollable.hpp"
#include <memory>

class BonusDice : public virtual Rollable {
public:
    BonusDice(std::unique_ptr<Rollable> dice);
    unsigned roll() override;
    BonusDice() = default;
    virtual ~BonusDice() override;
protected:
    std::unique_ptr<Rollable> baseDice;
};