#pragma once

#include "mesh.h"

class Object
{
public:
    Object();

    point3 pos;
    direction dir;

    void draw();

    Mesh* mesh;
};