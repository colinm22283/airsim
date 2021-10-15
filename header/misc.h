#pragma once

#include "math.h"

#define PI = 3.14159265359;

#define radians(deg) ( deg / 180 * PI )
#define degrees(rad) ( rad * 180 / PI )

inline double roundTo(double x, u_int8_t places)
{ return round(x * pow(10, places)) / pow(10, places); }