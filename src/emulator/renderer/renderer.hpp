#pragma once
#include <emulator/config.hpp>

class Renderer
{
private:
public:
    Renderer(uint width, uint height);
    ~Renderer();

    bool shouldClose();
    void render(const std::function<void(Renderer &)> &render_fn);
};