#include <pch.hpp>
#include <renderer.hpp>
#include <raylib.h>

Renderer::Renderer(int width, int height, const char *title)
{
    InitWindow(width, height, title);
}

void Renderer::start(std::function<void(void)> fn, std::function<void(void)> close, bool *over)
{
    while (!WindowShouldClose())
    {
        if (*over)
        {
            break;
        }

        fn();
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    close();
}

Renderer::~Renderer()
{
    CloseWindow();
}