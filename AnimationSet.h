#ifndef ANIMATION_SET_H
#define ANIMATION_SET_H

#include "Animation.h"
using namespace std;

class AnimationSet {
public:
    string imageName;
    SDL_Texture *spriteSheet;
    // holds the sprite sheet image for all of our animations

    SDL_Texture *whiteSpreadSheet; // use this sprite sheet to show damage
    list<Animation> animations;

    ~AnimationSet(); // properly delete the sprite sheet

    Animation *getAnimation(string name);

    // TODO: loadAnimationSet
};

#endif /* ANIMATION_SET_H */
