#include <malloc.h>
#include <math.h>

#include "color.h"
#include "render.h"
#include "console.h"

#include "sim.h"
#include "simFlags.h"

std::vector<Sim::particle> Sim::parts;

void Sim::start()
{
    for (int i = 200; i < 400; i += 20)
    {
        for (int j = 200; j < 400; j += 20)
        {
            Sim::parts.push_back({
                (double)i, (double)j,
                (double)j - 200, (double)i - 200,
                Sim::particleColor::RED
            });
        }
    }
}

void Sim::update()
{
    for (int i = 0; i < (int)Sim::parts.size(); i++)
    {
        Sim::parts[i].vx -= (Sim::parts[i].x - 250) / 10;
        Sim::parts[i].vy -= (Sim::parts[i].y - 250) / 10;

        Sim::parts[i].x += Sim::parts[i].vx;
        Sim::parts[i].y += Sim::parts[i].vy;
    }
}

void Sim::render()
{
    for (int i = 0; i < (int)Sim::parts.size(); i++)
    {
        particle p = Sim::parts[i];

        switch (SimFlags::renderMode)
        {
        case PARTICLE:
        {
            switch (p.c)
            {
            case WHITE:
                Render::setColor({ 255, 255, 255, 255 });
                break;
            case RED:
                Render::setColor({ 255, 0, 0, 255 });
                break;
            case YELLOW:
                Render::setColor({ 255, 255, 0, 255 });
                break;
            case GREEN:
                Render::setColor({ 0, 255, 0, 255 });
                break;
            case CYAN:
                Render::setColor({ 0, 255, 255, 255 });
                break;
            case BLUE:
                Render::setColor({ 0, 0, 255, 255 });
                break;
            case VIOLET:
                Render::setColor({ 255, 0, 255, 255 });
                break;
            }
            Render::drawPixel(p.x, p.y);
        } break;
        case VELOCITY:
        { } break;
        }

        if (SimFlags::drawVectors)
        {
            double vel = sqrt(pow(p.vx, 2) + pow(p.vy, 2));

            Render::drawLine(p.x, p.y, p.x + p.vx, p.y + p.vy);
        }
    }
}