#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <cmath>
#include <iostream>
#include <random>
#include <vector>

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "object.hpp"
#include "time.hpp"

class LimbData {
 public:
  float height;
  float tilt;
  float rotation;
  float width;
  float length;

  LimbData();
  LimbData(float h, float t, float r, float w, float l);
  ~LimbData();
};

class Tree : public Object {
 public:
  Tree();
  Tree(float x,
       float y,
       float z,
       float height,
       float width,
       int slices,
       int limb_count,
       GLuint bark_tex,
       GLuint leaf_text);
  ~Tree();

  void render();

  std::vector<LimbData*> limbs;

 private:
  int slices;
  int limb_count;

  GLuint bark_tex;
  GLuint leaf_tex;

  void trunk();
  void limb(float y, float tilt, float rotation, float width, float length);
  void leaves(float length, float width);
};

#endif
