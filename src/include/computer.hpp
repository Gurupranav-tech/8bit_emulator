#pragma once
#include <mutex>
#include <thread>
#include <renderer.hpp>
#include <clock.hpp>
#include <register.hpp>

class Computer
{
private:
    Renderer *renderer;
    unsigned int clock_speed;
    std::mutex over_mutex;
    bool over = false;
    Clock *clock;
    std::thread *computer_thread;

    // Computer Internals
    Register Aregister = Register(159, "A Register");
    Register Bregister = Register(0, "B Register");
    Register instruction_register = Register(0, "Instruction Register");

public:
    Computer(unsigned int clock_speed);
    ~Computer();

    void start();
    void set_over();
    void clear();

    friend std::thread;

protected:
    void execute();
};