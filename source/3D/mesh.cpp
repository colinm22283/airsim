#include <math.h>

#include <color.h>
#include <render.h>
#include <console.h>

#include <3D/mesh.h>
#include <3D/math.h>
#include <3D/engine3DFlags.h>
#include <3D/engine3DGlobal.h>

//                                               MESH CLASS
Mesh::Mesh()
{

}

void Mesh::draw(point3 pos)
{
    if (Engine3DFlags::drawWireframe)
    {
        Render::setColor({ 0, 255, 0 });

        for (int i = 0; i < (int)faces.size(); i++) // draw points
        {
            point2 pts[3] = { { 0, 0 }, { 0, 0 }, { 0, 0 } };
            for (int j = 0; j < 3; j++)
            {
                // check if point is in fov
                float xAngle = atan2f32(
                    faces[i].points[j]->pos.z + pos.z - Engine3DGlobal::camera.pos.z,
                    faces[i].points[j]->pos.x + pos.x - Engine3DGlobal::camera.pos.x
                );
                if (
                    xAngle > Engine3DGlobal::camera.dir.y - (Engine3DGlobal::camera.fov / 2) &&
                    xAngle < Engine3DGlobal::camera.dir.y + (Engine3DGlobal::camera.fov / 2)
                ) {
                    float yAngle = atan2f32(
                        faces[i].points[j]->pos.y + pos.y - Engine3DGlobal::camera.pos.y,
                        sqrtf32(
                            powf32(faces[i].points[j]->pos.x + pos.x - Engine3DGlobal::camera.pos.x, 2) +
                            powf32(faces[i].points[j]->pos.z + pos.z - Engine3DGlobal::camera.pos.z, 2)
                        )
                    );

                    pts[j] = {
                        (xAngle - Engine3DGlobal::camera.dir.y + (Engine3DGlobal::camera.fov / 2)) / Engine3DGlobal::camera.fov * Global::windowWidth,
                        (yAngle - Engine3DGlobal::camera.dir.x + (Engine3DGlobal::camera.fov / 2)) / Engine3DGlobal::camera.fov * Global::windowHeight
                    };

                    Render::drawRect(
                        pts[j].x - 2,
                        pts[j].y - 2,
                        4, 4
                    );
                }
            }

            for (int j = 0; j < 2; j++) Render::drawLine(pts[j].x, pts[j].y, pts[j + 1].x, pts[j + 1].y);
            Render::drawLine(pts[2].x, pts[2].y, pts[0].x, pts[0].y);
        }
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
    proto.faces.push_back((face){
        { &proto.verts[3], &proto.verts[5], &proto.verts[6] },
        (point3){ 0, 0, 1 }
    });
    proto.faces.push_back((face){
        { &proto.verts[3], &proto.verts[5], &proto.verts[7] },
        (point3){ 0, 0, 1 }
    });
    proto.faces.push_back((face){
        { &proto.verts[4], &proto.verts[5], &proto.verts[6] },
        (point3){ 1, 0, 0 }
    });
    proto.faces.push_back((face){
        { &proto.verts[5], &proto.verts[6], &proto.verts[7] },
        (point3){ 1, 0, 0 }
    });
    proto.faces.push_back((face){
        { &proto.verts[0], &proto.verts[1], &proto.verts[2] },
        (point3){ -1, 0, 0 }
    });
    proto.faces.push_back((face){
        { &proto.verts[1], &proto.verts[2], &proto.verts[3] },
        (point3){ -1, 0, 0 }
    });
    proto.faces.push_back((face){
        { &proto.verts[2], &proto.verts[3], &proto.verts[6] },
        (point3){ 0, 1, 0 }
    });
    proto.faces.push_back((face){
        { &proto.verts[3], &proto.verts[6], &proto.verts[7] },
        (point3){ 0, 1, 0 }
    });
    proto.faces.push_back((face){
        { &proto.verts[0], &proto.verts[4], &proto.verts[5] },
        (point3){ 0, -1, 0 }
    });
    proto.faces.push_back((face){
        { &proto.verts[0], &proto.verts[5], &proto.verts[6] },
        (point3){ 0, -1, 0 }
    });

    return proto;
}