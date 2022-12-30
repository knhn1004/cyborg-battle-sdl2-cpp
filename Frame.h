#ifndef FRAME_H
#define FRAME_H

#include "drawing_functions.h"
#include "globals.h"
#include "groupBuilder.h"
#include <SDL2/SDL.h>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>

using namespace std;

class Frame {
    int frameNumber;  // or frame index
    SDL_Rect clip;    // it's the region on the sprite sheet that we want to draw
    float duration;   // how long this frame should be displayed for
    SDL_Point offset; // the offset from the top left of the sprite sheet to the top left of the frame

    list<Group *> groups; // holds groups of additional data for the frame

    void Draw(SDL_Texture *spriteSheet, float x, float y);
    // TODO: loadFrame
};

#endif // !FRAME_H