#include <3D/object.h>
#include <3D/render3D.h>
#include <3D/engine3DFlags.h>

Object::Object()
{
    pos = { 0, 0, 0 };
    dir = { 0, 0, 0 };
    scale = { 1, 1, 1 };
}
Object::Object(point3 _pos, direction _dir, point3 _scale, mesh* _mesh, texture* _tex)
{
    pos = _pos;
    dir = _dir;
    scale = _scale;
    m = _mesh;
    tex = _tex;
}

void Object::draw()
{
    if (Engine3DFlags::drawWireframe)
    { Render3D::drawWireframe(m, pos, scale); }

    Render3D::drawTexture(tex, { 10, 10 });
}