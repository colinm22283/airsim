#pragma once

#include <vector>

#include <3D/math.h>

struct vertex
{
    point3 pos;
    point2 texCoord;
};
struct face
{
    int points[3];
    point3 dir;
};

struct mesh
{
    std::vector<vertex> verts;
    std::vector<face> faces;
};