#include "terrain.hpp"

Terrain::Terrain() {
  length = 60;
  width = 60;
  height = 10;
}

Terrain::~Terrain() {
  std::cout << "TERRAIN DECONSTRUCTOR" << std::endl;
}

void Terrain::render() {
  glPushMatrix();
  glTranslatef(-length / 2, 0.0, -width / 2);
  glColor3f(0.233, 0.545, 0.133);  // dark
  // glColor3f(0.420, 0.557, 0.137);
  glBegin(GL_POLYGON);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(length, 0.0, 0.0);
  glVertex3f(length, 0.0, width);
  glVertex3f(0.0, 0.0, width);
  glNormal3f(0.0, 1.0, 0.0);
  glEnd();
  glPopMatrix();
}
