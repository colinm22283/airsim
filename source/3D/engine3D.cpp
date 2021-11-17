#include <vector>

#include <3D/engine3D.h>
#include <3D/engine3DGlobal.h>
#include <3D/object.h>
#include <3D/meshLoader.h>

Engine3D::camera Engine3D::cam = { { 0, 0, 0 }, { 0, 0, 0 } };

void Engine3D::init()
{
    MeshLoader::loadMeshes();
}

void Engine3D::update()
{
    for (int i = 0; i < (int)Engine3DGlobal::objects.size(); i++)
    {
        Engine3DGlobal::objects[i].draw();
    }
}