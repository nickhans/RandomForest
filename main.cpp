#include "main.hpp"

GameManager::GameManager() : camera(), renderer(), light() {
  _window = nullptr;
  _windowWidth = 1024;
  _windowHeight = 768;
  _gameRunning = true;

  SDL_Init(SDL_INIT_VIDEO);

  // SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  _window = SDL_CreateWindow("A Trip Through The Woods | Nick Hanselman",
                             SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                             _windowWidth, _windowHeight,
                             SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  if (!_window)
    fatalError("SDL Window Could Not Be Created.");

  _context = SDL_GL_CreateContext(_window);
  if (!_context)
    fatalError("SDL GL Context Could Not Be Created.");
}

GameManager::~GameManager() {
  SDL_GL_DeleteContext(_context);
  SDL_DestroyWindow(_window);
  std::cout << "GAMEMANAGER DESTRUCTOR" << std::endl;
}

void GameManager::processInput() {
  SDL_Event event;
  while (SDL_PollEvent(&event) == true) {
    switch (event.type) {
      case SDL_QUIT:
        _gameRunning = false;
        break;
      case SDL_WINDOWEVENT:
        if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
          SDL_SetWindowSize(_window, event.window.data1, event.window.data2);
          reshape();
        }
        break;
      case SDL_KEYDOWN:
        _gameRunning = key(&camera);
        break;
      default:
        break;
    }
  }
}

void GameManager::display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glLoadIdentity();
  glPushMatrix();
  camera.set_eye_position();
  // set lighting
  light.set_light();
  // std::cout << "DISPLAY: " << renderer.tree.limbs.length << std::endl;
  renderer.render_scene();
  // std::cout << "SQUARE" << std::endl;
  glPopMatrix();
  glFlush();
  checkError("display");
  SDL_GL_SwapWindow(_window);
}

void GameManager::reshape() {
  SDL_GetWindowSize(_window, &_windowWidth, &_windowHeight);
  camera.set_asp((_windowHeight > 0) ? (double)_windowWidth / _windowHeight
                                     : 1);
  // std::cout << "New asp: " << camera.get_asp() << std::endl;
  glViewport(0, 0, _windowWidth, _windowHeight);
  camera.project();
}

void GameManager::run() {
  // std::cout << "RUN: " << renderer.tree.limbs.length << std::endl;
  reshape();
  while (_gameRunning) {
    processInput();
    display();
    SDL_Delay(5);
  }
  SDL_Quit();
}

int main(int argc, char* argv[]) {
  GameManager game;
  // std::cout << "MAIN: " << game.renderer.tree.limbs.length << std::endl;

  game.run();
  return EXIT_SUCCESS;
}
