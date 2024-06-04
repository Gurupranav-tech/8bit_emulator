#pragma once
#include <functional>
#include <register.hpp>

class Renderer
{
public:
    Renderer(int width, int height, const char *title);
    ~Renderer();

    void start(std::function<void(Renderer *renderer)> fn, std::function<void(void)> close, bool *over);
    void render_clock(bool state);

    void render_register(Register reg, int pref = 0);
};