enum SF_RENDER_MODE { PARTICLE, VELOCITY };

namespace SimFlags
{
    extern bool debugMode;
    extern bool drawVelocityVectors;
    extern bool drawForceVectors;

    extern double forceMult;
    extern double forceExp;

    extern SF_RENDER_MODE renderMode;
}

inline bool SimFlags::debugMode = false;
inline bool SimFlags::drawVelocityVectors = true;
inline bool SimFlags::drawForceVectors = true;

inline double SimFlags::forceMult = 0.05;
inline double SimFlags::forceExp = 3;

inline SF_RENDER_MODE SimFlags::renderMode = PARTICLE;