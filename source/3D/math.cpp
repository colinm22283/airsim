#include <math.h>

#include <global.h>

#include <3D/math.h>

float fixAng(float x)
{ float temp; return temp = fmodf32(x, PI * 2) < 0 ? PI * 2 + temp : temp; }