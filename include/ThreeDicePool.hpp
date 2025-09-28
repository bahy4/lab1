#pragma once
#include "Rollable.hpp"
#include <memory>

class ThreeDicePool : public Rollable{
public:
    ThreeDicePool(std::unique_ptr<Rollable> d1,
                  std::unique_ptr<Rollable> d2,
                  std::unique_ptr<Rollable> d3);
    unsigned roll() override;
    ~ThreeDicePool() override;

private:
    std::unique_ptr<Rollable> d1, d2, d3;
};