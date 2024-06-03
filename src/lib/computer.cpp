#include <pch.hpp>
#include <computer.hpp>
#include <logger.hpp>

Computer::Computer(unsigned int clock_speed)
{
    Log::init();
    INFO("Initializing Renderer");
    renderer = new Renderer(WIDTH, HEIGHT, TITLE);
    clock_speed = clock_speed;
    clock = new Clock(clock_speed);

    computer_thread = new std::thread(std::bind(&Computer::execute, this));
}

Computer::~Computer()
{
    computer_thread->join();
    delete computer_thread;
    delete clock;
    delete renderer;
}

void Computer::execute()
{
    std::function<bool(void)> fn = [&]() -> bool
    {
        if (over)
        {
            return false;
        }

        return true;
    };
    std::function<void(void)> over_bind = std::bind(&Computer::set_over, this);

    INFO("Starting Computer");
    clock->tick(fn, over_bind);
}

void Computer::set_over()
{
    over_mutex.lock();
    over = true;
    over_mutex.unlock();
}

void Computer::start()
{
    INFO("Starting Renderer");
    std::function<void(Renderer *)> fn = [&](Renderer *renderer)
    {
        renderer->render_clock(this->clock->get_state());
    };

    renderer->start(fn, std::bind(&Computer::set_over, this), &over);
}