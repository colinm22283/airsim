#pragma once

#include <3D/mesh.h>

namespace Primatives
{
    extern Mesh createPyramid(float width, float height, float length);
    extern Mesh createBlock(float width, float height, float length);
}
inline Mesh Primatives::createPyramid(float width, float height, float length)
{
    Mesh proto;

    proto.verts.push_back((vertex){ (point3){ 0, 0, 0 }, (point2){ 1, 1 } }); //                       0
    proto.verts.push_back((vertex){ (point3){ 0, 0, length }, (point2){ 0, 0 } }); //                  1
    proto.verts.push_back((vertex){ (point3){ width, 0, 0 }, (point2){ 2, 1 } }); //                   2
    proto.verts.push_back((vertex){ (point3){ width, 0, length }, (point2){ 0, 0 } }); //              3
    proto.verts.push_back((vertex){ (point3){ width / 2, height, length / 2 }, (point2){ 2, 1 } }); // 4

    return proto;
}
inline Mesh Primatives::createBlock(float width, float height, float length)
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
    proto.faces.push_back((face){
        { &proto.verts[1], &proto.verts[3], &proto.verts[5] },
        (point3){ 0, 0, 1 }
    });
    proto.faces.push_back((face){
        { &proto.verts[3], &proto.verts[5], &proto.verts[7] },
        (point3){ 0, 0, 1 }
    });
    proto.faces.push_back((face){
        { &proto.verts[0], &proto.verts[2], &proto.verts[4] },
        (point3){ 0, 0, -1 }
    });
    proto.faces.push_back((face){
        { &proto.verts[2], &proto.verts[4], &proto.verts[6] },
        (point3){ 0, 0, -1 }
    });

    return proto;
}