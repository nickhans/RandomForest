#ifndef __TERRAIN_HPP__
#define __TERRAIN_HPP__

#include <iostream>

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Terrain {
 public:
  Terrain();
  ~Terrain();

  void render();

 private:
  float length;
  float width;
  float height;
};

#endif
