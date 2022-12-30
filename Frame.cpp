#include "Frame.h"

void Frame::Draw(SDL_Texture *spriteSheet, float x, float y) {
    SDL_Rect dest; // destination of where to draw the frame
    dest.x = x + offset.x;
    dest.y = y + offset.y;
    dest.w = clip.w;
    dest.h = clip.h;

    renderTexture(spriteSheet, globals::renderer, dest, &clip);
}