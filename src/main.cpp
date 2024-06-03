#include <pch.hpp>
#include <computer.hpp>

int main(int argc, char **argv)
{
    Log::init();
    if (argc != 2)
    {
        ERROR("Invalid Usage: Requires clock speed");
        return 1;
    }
    unsigned int clock_speed = std::atoi(argv[1]);

    Computer computer(clock_speed);

    computer.start();
}