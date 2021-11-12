#pragma once

#include "mesh.h"

class Object
{
public:
    Object();
    Object(point3 _pos, direction _dir, Mesh* _mesh);

    point3 pos;
    direction dir;

    void draw();

    Mesh* mesh;
};