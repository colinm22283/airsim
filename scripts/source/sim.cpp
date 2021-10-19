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

void Sim::start()
{
    for (int i = 0; i < 50; i += 3)
    {
        for (int j = 100; j < 300; j += 3)
        {
            SimFlags::parts.push_back((particle){
                (double)i, (double)j,
                7.0, 0.0,
                Sim::particleColor::RED
            });
        }
    }
}

void Sim::update()
{
    if (spawnTimer >= SimFlags::spawnInterval)
    {
        SimFlags::parts.push_back((particle){
            50, 150,
            7, 0,
            Sim::particleColor::RED
        });

        // for (int i = 0; i < 50; i += 3)
        // {
        //     for (int j = 100; j < 300; j += 3)
        //     {
        //         SimFlags::parts.push_back({
        //             (double)i, (double)j,
        //             7, 0,
        //             Sim::particleColor::RED
        //         });
        //     }
        // }
        spawnTimer = 0;
    }

    spawnTimer++;

    for (int i = 0; i < (int)SimFlags::parts.size(); i++)
    {
        for (int j = 0; j < (int)SimFlags::objects.size(); j++)
        {
            point vector = SimFlags::objects[j].getForce(SimFlags::parts[i].x, SimFlags::parts[i].y);

            SimFlags::parts[i].vx -= vector.x;
            SimFlags::parts[i].vy -= vector.y;
        }

        SimFlags::parts[i].x += SimFlags::parts[i].vx;
        SimFlags::parts[i].y += SimFlags::parts[i].vy;
        SimFlags::parts[i].life++;

        if (SimFlags::parts[i].life >= SimFlags::particleLifespan)
        {
            SimFlags::parts.erase(SimFlags::parts.begin() + i);
        }
    }
}

void Sim::render()
{
    for (int i = 0; i < (int)SimFlags::parts.size(); i++)
    {
        particle p = SimFlags::parts[i];

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