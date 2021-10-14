#include <malloc.h>
#include <math.h>

#include "color.h"
#include "render.h"
#include "console.h"
#include "engine.h"

#include "sim.h"
#include "simFlags.h"
#include "obj.h"


long spawnTimer = 0;

std::vector<object> Sim::objects;
std::vector<Sim::particle> Sim::parts;

void Sim::start()
{
    // Sim::parts.push_back({
    //     150, 150,
    //     10, 0,
    //     Sim::particleColor::RED
    // });
}

void Sim::update()
{
    if (spawnTimer >= SimFlags::spawnInterval)
    {
        for (int i = 0; i < 50; i += 3)
        {
            for (int j = 100; j < 300; j += 3)
            {
                Sim::parts.push_back({
                    (double)i, (double)j,
                    7, 0,
                    Sim::particleColor::RED
                });
            }
        }
        spawnTimer = 0;
    }

    spawnTimer += 1;

    for (int i = 0; i < (int)Sim::parts.size(); i++)
    {
        for (int j = 0; j < (int)Sim::objects.size(); j++)
        {
            point vector = Sim::objects[j].getForce(Sim::parts[i].x, Sim::parts[i].y);

            Sim::parts[i].vx -= vector.x;
            Sim::parts[i].vy -= vector.y;
        }

        Sim::parts[i].x += Sim::parts[i].vx;
        Sim::parts[i].y += Sim::parts[i].vy;
        Sim::parts[i].life += Engine::deltaTime;

        if (Sim::parts[i].life >= SimFlags::particleLifespan)
        {
            Sim::parts.erase(Sim::parts.begin() + i);
        }
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

        if (SimFlags::drawVelocityVectors)
        {
            //double vel = sqrt(pow(p.vx, 2) + pow(p.vy, 2));

            Render::drawLine(p.x, p.y, p.x + p.vx, p.y + p.vy);
        }
    }
}