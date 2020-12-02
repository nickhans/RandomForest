#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class TextureManager {
 public:
  GLuint grass;
  GLuint bark;
  GLuint leaf;

  TextureManager();
  ~TextureManager();

 private:
  GLuint load_texture(const char* texture_path);
};

#endif
