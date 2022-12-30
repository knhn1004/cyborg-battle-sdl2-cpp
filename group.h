#include "dataGroupType.h"
#include <SDL2/SDL.h>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

using namespace std;
#ifndef GROUP_H
#define GROUP_H

// ABSTRACT CLASS
// groups manage a frames data

class Group {
public:
    DataGroupType type; // describes its name, type and other rules
    Group() {
        // nothing...
    }
    Group(DataGroupType type) {
        this->type = type;
    }
    // how many bits of data in here
    virtual int numberOfDataInGroup() = 0;
    /*add to group using string. Converts string into correct data for each group type*/
    virtual void addToGroup(string str) = 0;

    virtual void draw() = 0;
};

#endif