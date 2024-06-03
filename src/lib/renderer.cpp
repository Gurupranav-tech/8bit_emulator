#include <pch.hpp>
#include <renderer.hpp>
#include <raylib.h>

Renderer::Renderer(int width, int height, const char *title)
{
    InitWindow(width, height, title);
}

void Renderer::start(std::function<void(void)> fn)
{
    while (!WindowShouldClose())
    {
        fn();
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
}

Renderer::~Renderer()
{
    CloseWindow();
}