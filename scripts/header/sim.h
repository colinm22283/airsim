#pragma once

#include <vector>

#include "../scripts/header/obj.h"

namespace Sim
{
    enum particleColor { WHITE, RED, YELLOW, GREEN, CYAN, BLUE, VIOLET };
    struct particle
    {
        double x = 0;
        double y = 0;
        double vx = 0;
        double vy = 0;
        particleColor c;
    };

    extern std::vector<object> objects;
    extern std::vector<particle> parts;

    void start();
    void update();
    void render();
}