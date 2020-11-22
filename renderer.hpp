#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <iostream>
#include <random>
#include <vector>

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "time.hpp"
#include "tree.hpp"

class Renderer {
 public:
  // Tree tree;
  std::vector<Tree*> trees;

  Renderer();
  ~Renderer();

  void render_scene();

 private:
  void render_axis();
};

#endif
