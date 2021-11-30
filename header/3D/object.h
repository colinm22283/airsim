#pragma once

#include <3D/mesh.h>
#include <3D/texture.h>

struct Object
{
    Object();
    Object(point3 _pos, direction _dir, point3 scale, mesh* _mesh, texture* _tex);

    point3 pos;
    direction dir;
    point3 scale;

    void draw();

    mesh* m;
    texture* tex;
};