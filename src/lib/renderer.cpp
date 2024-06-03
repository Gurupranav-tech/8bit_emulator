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

Renderer::~Renderer()
{
    CloseWindow();
}