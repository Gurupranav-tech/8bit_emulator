#pragma once
#include <emulator/config.hpp>

class Clock
{
private:
    uint speed;
    bool state = true;

public:
    Clock(uint speed);

    void tick(std::function<void(void)> fn, bool *over);

    inline bool get_state() const noexcept { return state; }
};