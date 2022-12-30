#include "AnimationSet.h"

AnimationSet::~AnimationSet() {
    cleanup(spriteSheet);
    if (whiteSpriteSheet != nullptr) {
        cleanup(whiteSpriteSheet);
    }
}

Animation *AnimationSet::getAnimation(string name) {
    for (
        list<Animation>::iterator it = animations.begin();
        it != animations.end();
        it++) {
        if (it->name == name) {
            return &(*it);
        }
    }
    return nullptr;
}

void AnimationSet::loadAnimationSet(string fileName, list<DataGroupType> &groupTypes, bool setColorKey, int transparentPixelIndex, bool createWhiteTexture) {
    ifstream file;
    string resPath = getResourcePath();
    file.open(resPath + fileName);
    if (file.good()) {
        getline(file, imageName);
        if (setColorKey) {
            SDL_Surface *spriteSurface = loadSurface(resPath + imageName, globals::renderer);

            // for transparency, we will grab the [transparentPixelIndex] from the surface we just made
            SDL_Color *transparentPixel = &spriteSurface->format->palette->colors[transparentPixelIndex];
            SDL_SetColorKey(spriteSurface, 1, SDL_MapRGB(spriteSurface->format, transparentPixel->r, transparentPixel->g, transparentPixel->b));

            spriteSheet = convertSurfaceToTexture(spriteSurface, globals::renderer, false);

            if (createWhiteTexture) {
                SDL_Surface *whiteSurface = loadSurface(resPath + "allwhite.png", globals::renderer);
                surfacePaletteSwap(spriteSurface, whiteSurface);
                SDL_SetColorKey(spriteSurface, 1, SDL_MapRGB(spriteSurface->format, transparentPixel->r, transparentPixel->g, transparentPixel->b));
                whiteSpriteSheet = convertSurfaceToTexture(spriteSurface, globals::renderer, false); // create the texture whilst destroying the surface

                cleanup(whiteSurface);
            } else {
                whiteSpriteSheet = NULL;
            }

            cleanup(spriteSurface);
        } else
            spriteSheet = loadTexture(resPath + imageName, globals::renderer);

        string buffer;
        getline(file, buffer);
        stringstream ss;
        buffer = globals::clipOffDataHeader(buffer);
        ss << buffer;
        int numberOfAnimations;
        ss >> numberOfAnimations;

        for (int i = 0; i < numberOfAnimations; i++) {
            Animation newAnimation;
            newAnimation.loadAnimation(file, groupTypes);
            animations.push_back(newAnimation);
        }
    }
    file.close();
}
