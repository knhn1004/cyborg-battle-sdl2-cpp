#ifndef GLOBALS_H
#define GLOBALS_H

#include "randomNumber.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class Globals {
public:
    // math helpers
    static const float PI;

    // useful for me as a dev
    static bool debugging;

    // SDL related
    static int ScreenWidth, ScreenHeight, ScreenScale;
    static SDL_Renderer *renderer;
};

#endif /* GLOBALS_H */
