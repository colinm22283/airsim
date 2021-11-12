#pragma once

#include <vector>

#include <3D/math.h>
#include <3D/object.h>

namespace Engine3D
{
    struct camera
    {
        point3 pos;
        direction dir;
        float fov;
    };
    extern camera cam;

    extern void update();
}