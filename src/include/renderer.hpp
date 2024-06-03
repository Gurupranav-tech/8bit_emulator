#pragma once
#include <functional>

class Renderer
{
public:
    Renderer(int width, int height, const char *title);
    ~Renderer();

    void start(std::function<void(void)> fn);
};