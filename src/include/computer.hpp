#pragma once
#include <mutex>
#include <thread>
#include <renderer.hpp>
#include <clock.hpp>

class Computer
{
private:
    Renderer *renderer;
    unsigned int clock_speed;
    std::mutex over_mutex;
    bool over = false;
    Clock *clock;
    std::thread *computer_thread;

public:
    Computer(unsigned int clock_speed);
    ~Computer();

    void start();
    void set_over();

    friend std::thread;

protected:
    void execute();
};