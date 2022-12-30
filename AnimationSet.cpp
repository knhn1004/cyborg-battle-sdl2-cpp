#include "AnimationSet.h"

AnimationSet::~AnimationSet() {
    cleanup(spriteSheet);
    if (whiteSpreadSheet != nullptr) {
        cleanup(whiteSpreadSheet);
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
