#include "3D/object.h"

Object::Object()
{
    pos = { 0, 0, 0 };
    dir = { 0, 0, 0 };
}
Object::Object(point3 _pos, direction _dir, Mesh* _mesh)
{
    pos = _pos;
    dir = _dir;
    mesh = _mesh;
}

void Object::draw()
{
    mesh->draw(pos);
}