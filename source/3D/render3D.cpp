#include <render.h>

#include <3D/render3D.h>
#include <3D/texture.h>
#include <3D/mesh.h>
#include <3D/engine3DGlobal.h>
#include <3D/engine3DFlags.h>

void Render3D::drawTexture(texture* tex, point2 pos)
{
    for (int x = 0; x < tex->width; x++) for (int y = 0; y < tex->height; y++)
    { Render::drawPixel(x + pos.x, y + pos.y, tex->pixels[x][y]); }
}

void Render3D::drawWireframe(mesh* m, point3 pos, point3 scale)
{
    float camDirY = fixAng(Engine3DGlobal::camera.dir.y);
    float camDirX = Engine3DGlobal::camera.dir.x;

    if (Engine3DFlags::drawWireframe)
    {
        Render::setColor({ 0, 255, 0 });

        for (int i = 0; i < (int)m->faces.size(); i++) // draw points
        {
            for (int k = 0; k < 3; k++)
            {
                float xAngle = atan2f32(
                    (m->verts[m->faces[i].points[k]].pos.z * scale.z) + pos.z - Engine3DGlobal::camera.pos.z,
                    (m->verts[m->faces[i].points[k]].pos.x * scale.x) + pos.x - Engine3DGlobal::camera.pos.x
                );
                if (
                    xAngle > camDirY - (Engine3DGlobal::camera.fov / 2) &&
                    xAngle < camDirY + (Engine3DGlobal::camera.fov / 2)
                ) {
                    point2 pts[3] = { { 0, 0 }, { 0, 0 }, { 0, 0 } };
                    for (int j = 0; j < 3; j++)
                    {
                        // check if point is in fov
                        float xAngle = atan2f32(
                            (m->verts[m->faces[i].points[j]].pos.z * scale.z) + pos.z - Engine3DGlobal::camera.pos.z,
                            (m->verts[m->faces[i].points[j]].pos.x * scale.x) + pos.x - Engine3DGlobal::camera.pos.x
                        );
                        float yAngle = atan2f32(
                            m->verts[m->faces[i].points[j]].pos.y * scale.y + pos.y - Engine3DGlobal::camera.pos.y,
                            sqrtf32(
                                powf32((m->verts[m->faces[i].points[j]].pos.x * scale.x) + pos.x - Engine3DGlobal::camera.pos.x, 2) +
                                powf32((m->verts[m->faces[i].points[j]].pos.z * scale.z) + pos.z - Engine3DGlobal::camera.pos.z, 2)
                            )
                        );

                        pts[j] = {
                            (xAngle - camDirY + (Engine3DGlobal::camera.fov / 2)) / Engine3DGlobal::camera.fov * Global::windowWidth,
                            (yAngle - camDirX + (Engine3DGlobal::camera.fov / 2)) / Engine3DGlobal::camera.fov * Global::windowHeight
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