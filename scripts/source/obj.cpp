#include <math.h>
#include <string>

#include "console.h"
#include "render.h"

#include "obj.h"
#include "simFlags.h"

object::object()
{
    c = { 0, 0, 0, 255 };
}
object::object(color _c)
{
    c = _c;
}

point object::getForce(double a, double b)
{
    int fvCount = 0;
    point forceVector = { 0, 0 };

    for (int i = 0; i < (int)points.size() - 1; i++)
    {
        point p1 = points[i];
        point p2 = points[i + 1];
        double m = ((p2.y - p1.y) / (p2.x - p1.x));
        double c = p1.y - p1.x * m;

        if (p1.x == p2.x) forceVector.x += a - p1.x;
        else
        {
            double x = (b * m - c * m + a) / (1 + pow(m, 2));
            // Render::setColor({ 0, 0, 255, 255 });
            // Render::drawRect(x, 0, 1, 300);
            // Render::fillRect(x - 3, m * x + c - 3, 6, 6);
            // Render::drawLine(x, m * x + c, a, b);

            // Console::print("M: " + std::to_string(m));
            // Console::print("C: " + std::to_string(c));
            // Console::print("X: " + std::to_string(x));
            // Console::print("Y: " + std::to_string(m * x + c));

            forceVector.x += x - a;
            forceVector.y += (m * x + c) - b;
            fvCount++;

            // Console::print("X: " + std::to_string(forceVector.x));
            // Console::print("Y: " + std::to_string(forceVector.y));
        }

        // Console::print(std::to_string(distance));
    }

    forceVector.x /= fvCount;
    forceVector.y /= fvCount;

    double mag = sqrt(pow(forceVector.x, 2) + pow(forceVector.y, 2));
    forceVector.x /= mag;
    forceVector.y /= mag;

    point magVector = {
        pow(mag * SimFlags::magMult, SimFlags::forceExp),
        pow(mag * SimFlags::magMult, SimFlags::forceExp)
    };

    forceVector.x *= magVector.x;
    forceVector.y *= magVector.y;

    forceVector.x *= SimFlags::forceMult;
    forceVector.y *= SimFlags::forceMult;

    int pvCount = 0;
    point partVector = { 0, 0 };
    for (int i = 0; i < (int)SimFlags::parts.size(); i++)
    {
        
    }

    // forceVector.x = forceVector.x * pow(mag, SimFlags::forceExp);
    // forceVector.y = forceVector.y * pow(mag, SimFlags::forceExp);

    // Console::print("X: " + std::to_string(forceVector.x));
    // Console::print("Y: " + std::to_string(forceVector.y));

    return forceVector;
}

void object::draw()
{
    for (int i = 0; i < (int)points.size() - 1; i++)
    {
        Render::drawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
    }
}