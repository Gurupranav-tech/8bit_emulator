#pragma once
#include <renderer.hpp>

class Computer
{
private:
    Renderer *renderer;

public:
    Computer();
    ~Computer();

    void start();
};