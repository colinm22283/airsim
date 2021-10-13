#include <math.h>
#include <string>

#include "console.h"
#include "render.h"

#include "obj.h"

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
    point forceVector = { 0, 0 };

    for (int i = 0; i < (int)points.size() - 1; i++)
    {
        point p1 = points[i];
        point p2 = points[i + 1];
        double m = ((p2.y - p1.y) / (p2.x - p1.x));
        double c = p1.y - p1.x * m;
        double distance = -1;

        if (p1.x == p2.x) distance = p1.x - a;
        else
        {
            double x = (b * m - c * m + a) / pow(m, 2) / 2;
            distance = sqrt(pow(a - x, 2) + pow(b - (m * x + c), 2));

            forceVector.x += x;
            forceVector.y += m * x + c;
        }

        Console::print(std::to_string(distance));
    }

    return forceVector;
}

void object::draw()
{
    for (int i = 0; i < (int)points.size() - 1; i++)
    {
        Render::drawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
    }
}