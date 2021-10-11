enum SF_RENDER_MODE { PARTICLE, VELOCITY };

namespace SimFlags
{
    extern bool debugMode;
    extern bool drawVectors;

    extern SF_RENDER_MODE renderMode;
}

inline bool SimFlags::debugMode = false;
inline bool SimFlags::drawVectors = false;

inline SF_RENDER_MODE SimFlags::renderMode = PARTICLE;