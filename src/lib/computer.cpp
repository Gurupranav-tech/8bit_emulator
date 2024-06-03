#include <computer.hpp>
#include <pch.hpp>
#include <logger.hpp>

Computer::Computer()
{
    Log::init();
    INFO("Initializing Renderer");
    renderer = new Renderer(WIDTH, HEIGHT, TITLE);
}

Computer::~Computer()
{
    delete renderer;
}

void Computer::start()
{
    renderer->start([&]() {

    });
}