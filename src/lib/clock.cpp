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
        state = !state;
        if (!fn())
            break;

        if (!clock_speed)
        {
            char c;
            scanf("%c", &c);
            if (c == 'q')
                break;
            else
                continue;
        }
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(clock_speed / 2));
    }

    over();
}