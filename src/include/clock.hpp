#pragma once
#include <functional>

class Clock
{
public:
    Clock(unsigned int clock_speed);

    void tick(std::function<bool(void)> &fn, std::function<void(void)> &over);

private:
    unsigned int clock_speed;
};