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
    vertex* points[3];
    point3 dir;
};

class Mesh
{
public:
    Mesh();
    Mesh(vertex _verts[], int vCount, face _faces[], int fCount);

    std::vector<vertex> verts;
    std::vector<face> faces;

    void draw(point3 pos, point3 scale);
};