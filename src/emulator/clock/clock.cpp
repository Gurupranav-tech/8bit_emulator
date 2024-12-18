#include "clock.hpp"

Clock::Clock(uint speed)
    : speed(speed) {}

void Clock::tick(std::function<void(void)> fn, bool *over)
{
    while (!*over)
    {

        fn();
        if (speed == 0)
        {
            char q = getchar();
            if (q == 'q')
                return;
            else
                continue;
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(speed));
        }
    }
}