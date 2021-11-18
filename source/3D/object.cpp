#include "3D/object.h"

Object::Object()
{
    pos = { 0, 0, 0 };
    dir = { 0, 0, 0 };
    scale = { 1, 1, 1 };
}
Object::Object(point3 _pos, direction _dir, point3 _scale, Mesh* _mesh)
{
    pos = _pos;
    dir = _dir;
    scale = _scale;
    mesh = _mesh;
}

void Object::draw()
{
    mesh->draw(pos, scale);
}