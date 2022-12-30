#include "Frame.h"

void Frame::Draw(SDL_Texture *spriteSheet, float x, float y) {
    SDL_Rect dest; // destination of where to draw the frame
    dest.x = x + offset.x;
    dest.y = y + offset.y;
    dest.w = clip.w;
    dest.h = clip.h;

    renderTexture(spriteSheet, globals::renderer, dest, &clip);
}

void Frame::loadFrame(ifstream &file, list<DataGroupType> &groupTypes) {
    // Ok, we dragged these groupTypes allllll the way here, so we could construct groups on our frame to hold the data in
    GroupBuilder::buildGroups(groupTypes, frameData);

    string buffer;
    // frame - dud data saying this is a frame
    getline(file, buffer);
    // clip
    getline(file, buffer);
    stringstream ss;
    buffer = globals::clipOffDataHeader(buffer);
    ss << buffer;
    ss >> clip.x >> clip.y >> clip.w >> clip.h;
    // offset/pivot
    getline(file, buffer);
    ss.clear();
    buffer = globals::clipOffDataHeader(buffer);
    ss << buffer;
    ss >> offset.x >> offset.y;
    // duration
    getline(file, buffer);
    ss.clear();
    buffer = globals::clipOffDataHeader(buffer);
    ss << buffer;
    ss >> duration;
    // index
    getline(file, buffer);
    ss.clear();
    buffer = globals::clipOffDataHeader(buffer);
    ss << buffer;
    ss >> frameNumber;

    GroupBuilder::loadGroups(file, frameData);
}