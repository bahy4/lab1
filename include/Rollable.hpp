#pragma once

class Rollable {
public:
    virtual ~Rollable() = default;
    virtual unsigned roll() = 0;
};