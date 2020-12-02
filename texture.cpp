#include "texture.hpp"

TextureManager::TextureManager() {
  bark = load_texture("textures/bark.jpg");
  grass = load_texture("textures/grass.jpg");
  leaf = load_texture("textures/leaf.png");
}

TextureManager::~TextureManager() {}

GLuint TextureManager::load_texture(const char* texture_path) {
  SDL_Surface* image = nullptr;
  GLuint texture;
  image = IMG_Load(texture_path);
  if (!image) {
    std::cerr << "ERROR: Texture " << texture_path
              << "cannot be loaded. Skipping..." << std::endl;
    return UINT32_MAX;
  }

  GLint internalformat = GL_RGB;

  if (image->format->BytesPerPixel == 4) {
    std::cout << "TRANSPARENT: " << texture_path << std::endl;
    internalformat = GL_RGBA;
  }

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexImage2D(GL_TEXTURE_2D, 0, internalformat, image->w, image->h, 0,
               internalformat, GL_UNSIGNED_BYTE, image->pixels);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  SDL_FreeSurface(image);

  return texture;
}
