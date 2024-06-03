#pragma once
#include <functional>

class Clock
{
public:
    Clock(unsigned int clock_speed);

    void tick(std::function<bool(void)> &fn, std::function<void(void)> &over);
    inline bool get_state() { return state; }

private:
    unsigned int clock_speed;
    bool state = true;
};