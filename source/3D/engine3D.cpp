#include <vector>

#include <3D/engine3D.h>
#include <3D/object.h>

Engine3D::camera Engine3D::cam = { { 0, 0, 0 }, { 0, 0, 0 } };

std::vector<Object> Engine3D::objects;