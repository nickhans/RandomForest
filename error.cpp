#include "error.hpp"

void checkError(std::string where) {
  int err = glGetError();
  if (err)
    std::cerr << "ERROR: " << gluErrorString(err) << " [" << where << "]"
              << std::endl;
}

void fatalError(std::string message) {
  std::cerr << message << " ERROR: " << SDL_GetError() << std::endl;
  exit(EXIT_FAILURE);
}
