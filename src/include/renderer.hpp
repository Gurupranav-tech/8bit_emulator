#pragma once
#include <functional>

class Renderer
{
public:
    Renderer(int width, int height, const char *title);
    ~Renderer();

    void start(std::function<void(Renderer *renderer)> fn, std::function<void(void)> close, bool *over);
    void render_clock(bool state);
};