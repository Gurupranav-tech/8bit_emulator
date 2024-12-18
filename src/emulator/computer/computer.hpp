#pragma once
#include <emulator/config.hpp>
#include <emulator/clock/clock.hpp>
#include <emulator/renderer/renderer.hpp>

class Computer
{
private:
    Clock clock;
    Renderer renderer;
    uint status;
    std::thread *comp_thread;
    bool over;

public:
    Computer(uint speed, uint width, uint height);
    ~Computer();

    int start();

private:
    void render(Renderer &renderer);
    void exec();
};