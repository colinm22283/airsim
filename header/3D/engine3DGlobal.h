#pragma once

#include <vector>

#include <3D/math.h>
#include <3D/object.h>

struct __camData__
{
    point3 pos;
    direction dir;
};

namespace Engine3DGlobal
{
    extern __camData__ camera;

    extern std::vector<Object> objects;
}

inline __camData__ Engine3DGlobal::camera = {
    (point3){ 0, 0, 0 },
    (direction){ 0, 0, 0 }
};

inline std::vector<Object> Engine3DGlobal::objects;