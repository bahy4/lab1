#pragma once
#include "Rollable.hpp"
#include <memory>

class BonusDice : public Rollable {
public:
    BonusDice(std::unique_ptr<Rollable> dice);
    unsigned roll() override;
    ~BonusDice() override;
private:
    std::unique_ptr<Rollable> baseDice;
};