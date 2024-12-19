#include "renderer.hpp"
#include <raylib.h>

Renderer::Renderer(uint width, uint height)
    : width{width}, height{height}
{
    InitWindow(width, height, "8bit emulator");
    SetTargetFPS(60);
}

bool Renderer::shouldClose()
{
    return WindowShouldClose();
}

void Renderer::render_clock(const Clock &clock)
{
    constexpr u8 size = 50;
    DrawLine(2 * size, 0, 2 * size, size, WHITE);
    DrawLine(0, size, 2 * size, size, WHITE);
    DrawText("Clock", size / 2, 0, 25, WHITE);
    DrawCircle(size, size / 2 + 10, 10, clock.get_state() ? RED : WHITE);
}

void Renderer::render_register(const Register &reg, u8 pos)
{
    constexpr u8 size = 70;

    DrawRectangleLines(width - 3 * size, pos * size / 3 + size * pos, 3 * size, size, WHITE);
    DrawText(reg.get_name(), width - 3 * size + 5, pos * size / 3 + size * pos + 5, 20, WHITE);
    auto bits = reg.get_bits();
    for (int i = 0; i < 8; i++)
    {
        u8 bit = bits[i];
        DrawCircle(width - 3 * size + 15 + i * 25, pos * size / 3 + size * pos + 40, 10, bit ? RED : WHITE);
    }
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