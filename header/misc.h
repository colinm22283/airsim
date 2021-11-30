#pragma once

#include <math.h>
#include <fstream>
#include <string.h>

#ifndef PI
    #define PI = 3.14159265359;
#endif

#define radians(deg) ( deg / 180 * PI )
#define degrees(rad) ( rad * 180 / PI )

inline double roundTo(double x, u_int8_t places)
{ return round(x * pow(10, places)) / pow(10, places); }

struct point
{
    int x = 0;
    int y = 0;
};

inline void wi(std::ofstream* s, int x)
{
    char buf[4];
    std::copy(
        static_cast<const char*>(static_cast<const void*>(&x)),
        static_cast<const char*>(static_cast<const void*>(&x)) + 4,
        buf
    );
    for (int i = 0; i < 4; i++) *s << buf[i];
}
inline void wf(std::ofstream* s, float x)
{
    char buf[4];
    std::copy(
        static_cast<const char*>(static_cast<const void*>(&x)),
        static_cast<const char*>(static_cast<const void*>(&x)) + sizeof(x),
        buf
    );
    for (int i = 0; i < 4; i++) *s << buf[i];
}
inline void rb(std::ifstream* s, uint8_t* x)
{
    char buf;
    s->read(&buf, 1);
    memcpy(x, &buf, 1);
}
inline void ri(std::ifstream* s, int* x)
{
    char buf[4];
    for (int i = 0; i < 4; i++) s->read(&buf[i], 1);

    memcpy(x, &buf, 4);
}
inline void rf(std::ifstream* s, float* x)
{
    char buf[4];
    for (int i = 0; i < 4; i++) *s >> buf[i];
    
    memcpy(x, &buf, 4);
}