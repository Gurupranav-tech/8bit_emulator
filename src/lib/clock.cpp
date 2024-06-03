#include <clock.hpp>
#include <pch.hpp>

Clock::Clock(unsigned int clock_speed)
    : clock_speed(clock_speed)
{
}

void Clock::tick(std::function<bool(void)> &fn, std::function<void(void)> &over)
{
    while (true)
    {
        if (!fn())
            break;
        std::this_thread::sleep_for(std::chrono::milliseconds(clock_speed));
    }

    over();
}