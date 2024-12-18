#pragma once
#include <emulator/config.hpp>

class Clock
{
private:
    uint speed;

public:
    Clock(uint speed);

    void tick(std::function<void(void)> fn, bool *over);
};