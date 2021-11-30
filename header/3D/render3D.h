#pragma once

#include <3D/math.h>
#include <3D/mesh.h>
#include <3D/texture.h>

namespace Render3D
{
    extern void drawTexture(texture* tex, point2 pos);
    extern void drawWireframe(mesh* m, point3 pos, point3 scale);
}