#pragma once

#include <vector>

#include <3D/math.h>

struct vertex
{
    point2 pos;
    point2 texCoord;
};
struct face
{
    vertex* points[3];
};

class Mesh
{
public:
    Mesh();

    std::vector<vertex> verts;
    std::vector<face> faces;

    void draw();
};