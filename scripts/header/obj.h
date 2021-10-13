#pragma once

#include <vector>

#include "color.h"

struct point { double x; double y; };

class object
{
public:
    object();
    object(color _c);
    object(color _c, point _points[]);

    color c;

    std::vector<point> points;

    point getForce(double x, double y);
    void draw();
};