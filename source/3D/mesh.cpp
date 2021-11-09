#include <color.h>
#include <render.h>

#include <3D/mesh.h>
#include <3D/math.h>
#include <3D/engine3DFlags.h>

//                                               MESH CLASS
Mesh::Mesh()
{

}

void Mesh::draw(point3 pos)
{
    if (Engine3DFlags::drawWireframe)
    {
        Render::drawRect(0, 0, 10, 10, { 255, 0, 0 });
    }
}

Mesh Mesh::createBlock(float width, float height, float length)
{
    Mesh proto;

    proto.verts.push_back((vertex){ (point3){ 0, 0, 0 }, (point2){ 1, 1 } }); //                0
    proto.verts.push_back((vertex){ (point3){ 0, 0, length }, (point2){ 0, 0 } }); //           1
    proto.verts.push_back((vertex){ (point3){ 0, height, 0 }, (point2){ 1, 1 } }); //           2
    proto.verts.push_back((vertex){ (point3){ 0, height, length }, (point2){ 0, 0 } }); //      3
    proto.verts.push_back((vertex){ (point3){ width, 0, 0 }, (point2){ 2, 1 } }); //            4
    proto.verts.push_back((vertex){ (point3){ width, 0, length }, (point2){ 0, 0 } }); //       5
    proto.verts.push_back((vertex){ (point3){ width, height, 0 }, (point2){ 1, 1 } }); //       6
    proto.verts.push_back((vertex){ (point3){ width, height, length }, (point2){ 0, 0 } }); //  7

    proto.faces.push_back((face){
        { &proto.verts[0], &proto.verts[2], &proto.verts[4] },
        (point3){ 0, 0, -1 }
    });
    proto.faces.push_back((face){
        { &proto.verts[2], &proto.verts[4], &proto.verts[6] },
        (point3){ 0, 0, -1 }
    });
}