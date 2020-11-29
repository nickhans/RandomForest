#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "util.hpp"

class Light {
 public:
  bool on;
  Light();

  void set_light();

 private:
  int distance;
  float emission;
  float ambient;
  float diffuse;
  float specular;
  int shininess;
  int azimuth;
  float elevation;

  float x, z, r;

  void sun();
};

#endif
