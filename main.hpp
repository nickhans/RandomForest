#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <iostream>

#include <SDL2/SDL.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "camera.hpp"
#include "error.hpp"
#include "input.hpp"
#include "light.hpp"
#include "renderer.hpp"
#include "util.hpp"

class GameManager {
 public:
  Camera camera;
  Light light;
  Renderer* renderer;

  GameManager();
  ~GameManager();

  void run();

 private:
  void processInput();
  void display();
  void reshape();

  SDL_Window* _window;
  SDL_GLContext _context;
  int _windowWidth;
  int _windowHeight;
  bool _gameRunning;
};

#endif
