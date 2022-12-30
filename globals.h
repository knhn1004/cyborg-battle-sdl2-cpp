#ifndef GLOBALS
#define GLOBALS

#include "randomNumber.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
#include <string>

namespace globals {

// math helpers
extern const float PI;

// useful for me as a dev
extern bool debugging;

// SDL related
extern int screenWidth, screenHeight, screenScale;
extern SDL_Renderer *renderer;

// clips off header,
// e.g. "clip: 50 144 44 49"
// turns into "50 144 44 49"
extern std::string clipOffDataHeader(std::string data);

}; // namespace globals

#endif // !GLOBALS