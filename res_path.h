#ifndef RES_PATH_H
#define RES_PATH_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

/*
 * Get the resource path for resources located in res/subDir
 * It's assumed the project directory is structured like:
 * bin/
 *  the executable
 * res/
 *  Lesson1/
 *  Lesson2/
 *
 * Paths returned will be Lessons/res/subDir
 */
std::string getResourcePath(const std::string &subDir = "");

#endif