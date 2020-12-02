#include "terrain.hpp"

Terrain::Terrain() {
  length = 60.0f;
  width = 60.0f;
  height = 10.0f;
  texture = UINT32_MAX;
}

Terrain::Terrain(GLuint t) {
  length = 60.0f;
  width = 60.0f;
  height = 10.0f;
  texture = t;
}

Terrain::~Terrain() {
  std::cout << "TERRAIN DECONSTRUCTOR" << std::endl;
}

void Terrain::render() {
  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glPushMatrix();
  glTranslatef(-length / 2.0f, 0.0f, -width / 2.0f);
  glColor3f(0.233f, 0.545f, 0.133f);  // dark
  // glColor3f(0.420, 0.557, 0.137);
  glBindTexture(GL_TEXTURE_2D, texture);
  glBegin(GL_QUADS);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glNormal3f(0.0f, 1.0f, 0.0f);

  glTexCoord2f(0.0f, width / 9.0f);
  glVertex3f(0.0f, 0.0f, width);
  glNormal3f(0.0f, 1.0f, 0.0f);

  glTexCoord2f(length / 9.0f, width / 9.0f);
  glVertex3f(length, 0.0f, width);
  glNormal3f(0.0f, 1.0f, 0.0f);

  glTexCoord2f(length / 9.0f, 0.0f);
  glVertex3f(length, 0.0f, 0.0f);
  glNormal3f(0.0f, 1.0f, 0.0f);

  glEnd();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}
