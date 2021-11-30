#pragma once

#include <color.h>

struct texture
{
    int width;
    int height;

    color** pixels;

    void draw(int _x, int _y);
};
