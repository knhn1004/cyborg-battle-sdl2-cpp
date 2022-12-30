#include "TimeController.h"

const int TimeController::PLAY_STATE = 0,
          TimeController::PAUSE_STATE = 1;

TimeController::TimeController() : timeState(PLAY_STATE),
                                   lastUpdate(SDL_GetTicks()),
                                   dT(0) {
}

void TimeController::updateTime() {
    if (timeState == PAUSE_STATE) {
        dT = 0;
    } else {
        Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
        dT = timeDiff / 1000.0f; // move these milliseconds into the decimal place area
                                 // eg. 104 = 0.104 seconds
    }
    lastUpdate = SDL_GetTicks();
}

void TimeController::pause() {
    timeState = PAUSE_STATE;
}

void TimeController::resume() {
    timeState = PLAY_STATE;
}

void TimeController::reset() {
    dT = 0;
    lastUpdate = SDL_GetTicks();
}

// builds a global instance of TimeController object for us to use
TimeController TimeController::timeController;