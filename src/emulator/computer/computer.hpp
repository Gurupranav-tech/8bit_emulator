#pragma once
#include <emulator/config.hpp>
#include <emulator/clock/clock.hpp>
#include <emulator/renderer/renderer.hpp>
#include <emulator/register/register.hpp>

class Computer
{
private:
    // System clock
    Clock clock;

    Renderer renderer;
    uint status;
    std::thread *comp_thread;
    bool over;

    // CPU registers
    Register registerA;
    Register registerB;
    Register instructionRegister;

public:
    Computer(uint speed, uint width, uint height);
    ~Computer();

    int start();

private:
    void render(Renderer &renderer);
    void exec();
};