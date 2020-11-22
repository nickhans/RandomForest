#ifndef __ERROR_HPP__
#define __ERROR_HPP__

#include <iostream>

#include <SDL2/SDL.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GLUT/glut.h>
#endif

void checkError(std::string);
void fatalError(std::string);

#endif
