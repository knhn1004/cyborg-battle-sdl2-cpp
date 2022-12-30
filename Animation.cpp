#include "Animation.h"

Animation::Animation(string name) : name(name) {
}

int Animation::getNextFrameNumber(int frameNumber) {
    if (frameNumber + 1 < frames.size()) {
        return frameNumber + 1;
    }
    return 0;
}

Frame *Animation::getNextFrame(Frame *frame) {
    return getFrame(getNextFrameNumber(frame->frameNumber));
}

int Animation::getEndFrameNumber() {
    return frames.size() - 1;
}

Frame *Animation::getFrame(int frameNumber) {
    if (frames.size() == 0) {
        return nullptr;
    }

    list<Frame>::iterator it = frames.begin();
    advance(it, frameNumber);

    // for (int counter =0; counter <frameNumber && counter <frames.size(); counter++) {
    //	it++;
    // }

    return &(*it);
}

void Animation::loadAnimation(ifstream &file, list<DataGroupType> &groupTypes) {
    getline(file, name);
    string buffer;
    getline(file, buffer);
    stringstream ss;
    buffer = globals::clipOffDataHeader(buffer);
    ss << buffer;
    int numberOfFrames;
    ss >> numberOfFrames;
    for (int i = 0; i < numberOfFrames; i++) {
        Frame newFrame;
        newFrame.loadFrame(file, groupTypes);
        frames.push_back(newFrame);
    }
}