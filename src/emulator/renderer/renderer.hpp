#pragma once
#include <emulator/config.hpp>
#include <emulator/clock/clock.hpp>
#include <emulator/register/register.hpp>

class Renderer
{
private:
    uint width, height;

public:
    Renderer(uint width, uint height);
    ~Renderer();

    void render_clock(const Clock &clock);
    void render_register(const Register &reg, u8 pos = 0);

    bool shouldClose();
    void render(const std::function<void(Renderer &)> &render_fn);
};