//#include <Dice.hpp>
#include <ThreeDicePool.hpp>

#include "ThreeDicePool.hpp"

ThreeDicePool::ThreeDicePool(unsigned max, unsigned seed1, unsigned seed2, unsigned seed3)
    : d1(max, seed1), d2(max, seed2), d3(max, seed3) {}

unsigned ThreeDicePool::roll() {
    return d1.roll() + d2.roll() + d3.roll();
}

ThreeDicePool::~ThreeDicePool() = default;
