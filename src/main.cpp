#include <emulator/config.hpp>
#include <emulator/computer/computer.hpp>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ERROR("Invalid Usage: Clock Speed required");
        return 1;
    }

    uint speed = std::atoi(argv[1]);

    Computer computer{speed, 800, 600};
    return computer.start();
}