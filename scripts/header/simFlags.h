enum SF_RENDER_MODE { PARTICLE, VELOCITY };

namespace SimFlags
{
    extern bool debugMode;
    extern bool drawVelocityVectors;
    extern bool drawForceVectors;

    extern long spawnInterval;
    extern long particleLifespan;

    extern double forceMult;
    extern double forceExp;

    extern SF_RENDER_MODE renderMode;
}

inline bool SimFlags::debugMode = false;
inline bool SimFlags::drawVelocityVectors = true;
inline bool SimFlags::drawForceVectors = true;

inline long SimFlags::spawnInterval = 50;
inline long SimFlags::particleLifespan = 5000;

inline double SimFlags::forceMult = 0.2;
inline double SimFlags::forceExp = 1.01;

inline SF_RENDER_MODE SimFlags::renderMode = PARTICLE;