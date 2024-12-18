#include "renderer.hpp"
#include <raylib.h>

Renderer::Renderer(uint width, uint height)
{
    InitWindow(width, height, "8bit emulator");
}

bool Renderer::shouldClose()
{
    return WindowShouldClose();
}

void Renderer::render(const std::function<void(Renderer &)> &render_fn)
{
    BeginDrawing();
    render_fn(*this);
    EndDrawing();
}

Renderer::~Renderer()
{
    CloseWindow();
}