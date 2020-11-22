#include "input.hpp"

bool key(Camera* camera) {
  const Uint8* keys = SDL_GetKeyboardState(NULL);
  int shift = SDL_GetModState() & KMOD_SHIFT;

  if (keys[SDL_SCANCODE_ESCAPE]) {
    return false;

  } else if (keys[SDL_SCANCODE_RIGHT]) {
    camera->set_th(camera->get_th() + 5);
    // std::cout << "KEY PRESSED -- th: " << camera.get_th() << std::endl;
  } else if (keys[SDL_SCANCODE_LEFT]) {
    camera->set_th(camera->get_th() - 5);
  } else if (keys[SDL_SCANCODE_UP]) {
    camera->set_ph(camera->get_ph() - 5);
  } else if (keys[SDL_SCANCODE_DOWN]) {
    camera->set_ph(camera->get_ph() + 5);
  }
  return true;
}
