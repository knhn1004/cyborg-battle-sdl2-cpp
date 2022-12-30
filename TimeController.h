#ifndef TIME_CONTROLLER_H
#define TIME_CONTROLLER_H

#include <SDL2/SDL.h>
#include <iostream>

class TimeController {
    static const int PLAY_STATE, PAUSE_STATE;
    int timeState;
    Uint32 lastUpdate; // last time we checked how many ticks we were up to
    float dT;          // delta time (int seconds: 1 = 1 second, 0.5 = 0.5 seconds, etc)
                       // time since the last frame was rendered onto screen

    TimeController();
    void updateTime(); // update lastUpdate and dT
    void pause();
    void resume();
    void reset();

    static TimeController timeController;
};

#endif /* TIME_CONTROLLER_H */
