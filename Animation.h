#ifndef ANIMATION_H
#define ANIMATION_H

#include "Frame.h"
using namespace std;

class Animation {
public:
    string name;        // name of the animation
    list<Frame> frames; // list of frames in the animation

    Animation(string name = "");

    int getNextFrameNumber(int frameNumber);
    // returns the next frame number in the animation

    Frame *getNextFrame(Frame *frame);
    int getEndFrameNumber(); // returns the last frame number

    Frame *getFrame(int frameNumber);
    // returns the frame at the given frame number

    // TODO: loadAnimation
};

#endif // !ANIMATION_H