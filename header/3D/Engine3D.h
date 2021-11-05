#pragma once

#include <3D/math.h>

namespace Engine3D
{
    struct camera
    {
        point3 pos;
        direction dir;
        float fov;
    };
    camera cam;
}