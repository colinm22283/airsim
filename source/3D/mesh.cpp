#include <math.h>

#include <color.h>
#include <render.h>
#include <console.h>

#include <3D/mesh.h>
#include <3D/math.h>
#include <3D/engine3DFlags.h>
#include <3D/engine3DGlobal.h>

//                                               MESH CLASS
Mesh::Mesh() { }
Mesh::Mesh(vertex _verts[], int vCount, face _faces[], int fCount)
{
    for (int i = 0; i < vCount; i++)
    { verts.push_back(_verts[i]); }
    for (int i = 0; i < fCount; i++)
    { faces.push_back(_faces[i]); }
}

void Mesh::draw(point3 pos, point3 scale)
{
    if (Engine3DFlags::drawWireframe)
    {
        Render::setColor({ 0, 255, 0 });

        for (int i = 0; i < (int)faces.size(); i++) // draw points
        {
            for (int k = 0; k < 3; k++)
            {
                float xAngle = atan2f32(
                    (faces[i].points[k]->pos.z * scale.z) + pos.z - Engine3DGlobal::camera.pos.z,
                    (faces[i].points[k]->pos.x * scale.x) + pos.x - Engine3DGlobal::camera.pos.x
                );
                if (
                    xAngle > Engine3DGlobal::camera.dir.y - (Engine3DGlobal::camera.fov / 2) &&
                    xAngle < Engine3DGlobal::camera.dir.y + (Engine3DGlobal::camera.fov / 2)
                ) {
                    point2 pts[3] = { { 0, 0 }, { 0, 0 }, { 0, 0 } };
                    for (int j = 0; j < 3; j++)
                    {
                        // check if point is in fov
                        float xAngle = atan2f32(
                            (faces[i].points[j]->pos.z * scale.z) + pos.z - Engine3DGlobal::camera.pos.z,
                            (faces[i].points[j]->pos.x * scale.x) + pos.x - Engine3DGlobal::camera.pos.x
                        );
                        float yAngle = atan2f32(
                            faces[i].points[j]->pos.y * scale.y + pos.y - Engine3DGlobal::camera.pos.y,
                            sqrtf32(
                                powf32((faces[i].points[j]->pos.x * scale.x) + pos.x - Engine3DGlobal::camera.pos.x, 2) +
                                powf32((faces[i].points[j]->pos.z * scale.z) + pos.z - Engine3DGlobal::camera.pos.z, 2)
                            )
                        );

                        pts[j] = {
                            (xAngle - Engine3DGlobal::camera.dir.y + (Engine3DGlobal::camera.fov / 2)) / Engine3DGlobal::camera.fov * Global::windowWidth,
                            (yAngle - Engine3DGlobal::camera.dir.x + (Engine3DGlobal::camera.fov / 2)) / Engine3DGlobal::camera.fov * Global::windowHeight
                        };

                        Render::fillRect(
                            pts[j].x - 2,
                            pts[j].y - 2,
                            4, 4
                        );
                    }

                    for (int j = 0; j < 2; j++) Render::drawLine(pts[j].x, pts[j].y, pts[j + 1].x, pts[j + 1].y);
                    Render::drawLine(pts[2].x, pts[2].y, pts[0].x, pts[0].y);
                    break;
                }
            }
        }
    }
}