#include "light.hpp"

Light::Light() {
  on = true;
  distance = 30;
  emission = 0.05;
  ambient = 0.1;
  diffuse = 0.5;
  specular = 0.05;
  shininess = 1;
  azimuth = 180;
  elevation = 5.0;
  x = distance * Cos(azimuth);
  z = distance * Sin(azimuth);
  r = 0.5;
}

void Light::set_light() {
  glShadeModel(GL_SMOOTH);
  // ambient color
  float a_color[] = {ambient, ambient, ambient};
  // diffuse color
  float d_color[] = {diffuse, diffuse, diffuse};
  // specular color
  float s_color[] = {specular, specular, specular};
  // draw sun
  float position[] = {x, elevation, z};
  sun();

  glEnable(GL_NORMALIZE);
  glEnable(GL_LIGHTING);
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_AMBIENT, a_color);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, d_color);
  glLightfv(GL_LIGHT0, GL_SPECULAR, s_color);
  glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void Light::sun() {
  float color[] = {1.0, 1.0, 0.0, 1.0};
  float e_color[] = {0.0, 0.0, emission, 1.0};
  glPushMatrix();
  glTranslatef(x, elevation, z);
  glScalef(r, r, r);
  glColor3f(1.0, 1.0, 1.0);
  glMaterialf(GL_FRONT, GL_SHININESS, shininess);
  glMaterialfv(GL_FRONT, GL_SPECULAR, color);
  glMaterialfv(GL_FRONT, GL_EMISSION, e_color);

  for (int i = -90; i < 90; i += 15) {
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j <= 360; j += 30) {
      glVertex3f(Sin(j) * Cos(i), Sin(i), Cos(j) * Cos(i));
      glVertex3f(Sin(j) * Cos(i + 15), Sin(i + 15), Cos(j) * Cos(i + 15));
    }
    glEnd();
  }
  glPopMatrix();
}
