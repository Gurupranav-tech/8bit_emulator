#include <pch.hpp>
#include <renderer.hpp>
#include <raylib.h>

Renderer::Renderer(int width, int height, const char *title)
{
    InitWindow(width, height, title);
}

void Renderer::start(std::function<void(Renderer *renderer)> fn, std::function<void(void)> close, bool *over)
{
    while (!WindowShouldClose())
    {
        if (*over)
        {
            break;
        }

        fn(this);
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    close();
}

void Renderer::render_clock(bool state)
{
    DrawText("clock", 1, 1, 20, WHITE);
    DrawCircle(27, 27, 6, state == true ? RED : WHITE);
    DrawLine(0, 35, 60, 35, WHITE);
    DrawLine(60, 0, 60, 35, WHITE);
}

void Renderer::render_register(Register reg, int pref)
{
    auto name = reg.get_name();
    auto data = reg.get_bitdata();
    DrawText(name, WIDTH - 20 * strlen(name), 1 + pref * 50, 20, WHITE);
    DrawLine(WIDTH - 21 * strlen(name), 0 + pref * 50, WIDTH, 0 + pref * 50, WHITE);
    DrawLine(WIDTH - 21 * strlen(name), 0 + pref * 50, WIDTH - 21 * strlen(name), 40 + pref * 50, WHITE);
    for (int i = 0; i < 8; i++)
    {
        DrawCircle(WIDTH - 20 * strlen(name) + 21 * i, 29 + pref * 50, 6, data[i] == '1' ? RED : WHITE);
    }
    DrawLine(WIDTH - 21 * strlen(name), 40 + pref * 50, WIDTH, 40 + pref * 50, WHITE);
}

Renderer::~Renderer()
{
    CloseWindow();
}