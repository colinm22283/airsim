#include <math.h>
#include <string>

#include <global.h>
#include <console.h>

#include <3D/math.h>

float fixAng(float x)
{
    float temp = fmodf32(x, PI * 2);
    return (temp < 0) ? (temp + PI * 2) : temp;
}
float disAng(float a, float b)
{
    if (fabsf32(a - b) < 180)
    {
        return b - a;
    }
    else
    {
        return b - a - 180;
    }
}