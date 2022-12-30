#ifndef GLOBALS
#define GLOBALS

#include "randomNumber.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
#include <string>

namespace globals {

extern const float PI;

extern bool debugging;

extern int screenWidth, screenHeight, screenScale;

extern SDL_Renderer *renderer;
}; // namespace globals

#endif // !GLOBALS