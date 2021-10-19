#pragma once

#include <vector>

#include "sim.h"

enum SF_RENDER_MODE { PARTICLE, VELOCITY };

namespace SimFlags
{
    extern bool debugMode;
    extern bool drawVelocityVectors;
    extern bool drawForceVectors;

    extern long spawnInterval;
    extern long particleLifespan;

    extern double magMult;
    extern double forceMult;
    extern double forceExp;

    extern SF_RENDER_MODE renderMode;

    extern std::vector<object> objects;
    extern std::vector<Sim::particle> parts;
}

inline bool SimFlags::debugMode = false;
inline bool SimFlags::drawVelocityVectors = true;
inline bool SimFlags::drawForceVectors = true;

inline long SimFlags::spawnInterval = 50;
inline long SimFlags::particleLifespan = 75;

inline double SimFlags::magMult = 0.05;
inline double SimFlags::forceMult = 0.5;
inline double SimFlags::forceExp = 1.1;

inline SF_RENDER_MODE SimFlags::renderMode = PARTICLE;

inline std::vector<object> SimFlags::objects;
inline std::vector<Sim::particle> SimFlags::parts;