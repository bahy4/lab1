//#include <Dice.hpp>
#include <ThreeDicePool.hpp>

#include "ThreeDicePool.hpp"

ThreeDicePool::ThreeDicePool(std::unique_ptr<Rollable> d1,
                             std::unique_ptr<Rollable> d2,
                             std::unique_ptr<Rollable> d3)
    : d1(std::move(d1)), d2(std::move(d2)), d3(std::move(d3)) {}

unsigned ThreeDicePool::roll() {
    return d1->roll() + d2->roll() + d3->roll();
}

ThreeDicePool::~ThreeDicePool() = default;
