#include "globals.h"

namespace globals {

const float PI = M_PI;

bool debugging = true;

int screenWidth = 640, screenHeight = 352, screenScale = 2;

SDL_Renderer *renderer = nullptr;

} // namespace globals