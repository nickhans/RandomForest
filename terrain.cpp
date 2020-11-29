#include "terrain.hpp"

Terrain::Terrain() {
  length = 60.0f;
  width = 60.0f;
  height = 10.0f;
}

Terrain::~Terrain() {
  std::cout << "TERRAIN DECONSTRUCTOR" << std::endl;
}

void Terrain::render() {
  glPushMatrix();
  glTranslatef(-length / 2.0f, 0.0f, -width / 2.0f);
  glColor3f(0.233f, 0.545f, 0.133f);  // dark
  // glColor3f(0.420, 0.557, 0.137);
  glBegin(GL_POLYGON);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(length, 0.0f, 0.0f);
  glVertex3f(length, 0.0f, width);
  glVertex3f(0.0f, 0.0f, width);
  glNormal3f(0.0f, 1.0f, 0.0f);
  glEnd();
  glPopMatrix();
}
