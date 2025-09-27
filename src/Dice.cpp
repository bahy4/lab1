#include "Dice.hpp"

Dice::Dice(unsigned max, unsigned seed) 
    : max(max), dstr(1, max), reng(seed) {}

unsigned Dice::roll() {
    return dstr(reng);
}
