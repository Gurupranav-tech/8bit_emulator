#include "computer.hpp"

Computer::Computer(uint speed, uint width, uint height)
    : clock{speed}, renderer{width, height}, status{0}, over{false}, registerA{"A Register"}, registerB{"B Register"}, instructionRegister{"Instruction Register"}
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
}

void Computer::render(Renderer &renderer)
{
    renderer.render_clock(clock);
    renderer.render_register(registerA);
    renderer.render_register(registerB, 1);
}