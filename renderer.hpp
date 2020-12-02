#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <iostream>
#include <random>
#include <vector>

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "terrain.hpp"
#include "texture.hpp"
#include "time.hpp"
#include "tree.hpp"

class Renderer {
 public:
  TextureManager texture;

  Renderer();
  ~Renderer();

  void render_scene();

 private:
  Terrain* terrain;
  std::vector<Tree*> trees;

  void render_axis();
};

#endif
