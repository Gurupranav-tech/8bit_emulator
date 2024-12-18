#include "computer.hpp"

Computer::Computer(uint speed, uint width, uint height)
    : clock{speed}, renderer{width, height}, status{0}, over{false}
{
    comp_thread = new std::thread([&]()
                                  { this->clock.tick(std::bind(&Computer::exec, this), &this->over); });
}

Computer::~Computer()
{
    comp_thread->join();
    delete comp_thread;
}

int Computer::start()
{
    while (!renderer.shouldClose())
    {
        renderer.render(std::bind(&Computer::render, this, std::placeholders::_1));
    }
    over = true;

    return status;
}

void Computer::exec()
{
    static uint i = 0;
    INFO("Computer running. {}", i);
    i++;
}

void Computer::render(Renderer &renderer)
{
}