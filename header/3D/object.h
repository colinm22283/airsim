#pragma once

#include "mesh.h"

class Object
{
public:
    Object();
    Object(point3 _pos, direction _dir, point3 scale, Mesh* _mesh);

    point3 pos;
    direction dir;
    point3 scale;

    void draw();

    Mesh* mesh;
};