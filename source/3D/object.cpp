#include "3D/object.h"

Object::Object()
{
    pos = { 0, 0, 0 };
    dir = { 0, 0, 0 };
}

void Object::draw()
{
    mesh->draw(pos);
}