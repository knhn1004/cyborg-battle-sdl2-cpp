#ifndef ANIMATION_SET_H
#define ANIMATION_SET_H

#include "Animation.h"
using namespace std;

class AnimationSet {
public:
    string imageName;
    SDL_Texture *spriteSheet;
    // holds the sprite sheet image for all of our animations

    SDL_Texture *whiteSpriteSheet; // use this sprite sheet to show damage
    list<Animation> animations;

    ~AnimationSet(); // properly delete the sprite sheet

    Animation *getAnimation(string name);

    // TODO: loadAnimationSet
    void loadAnimationSet(
        string fileName,
        list<DataGroupType> &groupTypes,
        bool setColorKey = false, // SDL color key is used to make a color transparent
        int transparentPixelIndex = 0,
        bool createWhiteTexture = false);
};

#endif /* ANIMATION_SET_H */
