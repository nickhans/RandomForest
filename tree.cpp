#include "tree.hpp"

LimbData::LimbData() {
  height = 0;
  tilt = 0;
  rotation = 0;
  width = 10;
  length = 20;
}

LimbData::LimbData(float h, float t, float r, float w, float l) {
  height = h;
  tilt = t;
  rotation = r;
  width = w;
  length = l;
}

LimbData::~LimbData() {
  std::cout << "LIMB DESTRUCTOR" << std::endl;
}

Tree::Tree() : Object(0, 0, 0, 5, 1) {
  slices = 15;
}

Tree::Tree(float _x, float _y, float _z, float _h, float _w, int _s, int _lc)
    : Object(_x, _y, _z, _h, _w) {
  std::uniform_real_distribution<float> h_dist(height * 0.2, height);
  std::uniform_real_distribution<float> t_dist(30.0, 80.0);
  std::uniform_real_distribution<float> r_dist(0.0, 359.0);
  std::uniform_real_distribution<float> w_dist(width * 0.4, width * 0.7);
  std::uniform_real_distribution<float> l_dist(height * 0.2, height * 0.5);

  for (int i = 0; i < _lc; i++) {
    limbs.push_back(new LimbData(h_dist(rng), t_dist(rng), r_dist(rng),
                                 w_dist(rng), l_dist(rng)));
  }
  std::cout << "LIMBVEC LEN: " << limbs.size() << std::endl;
  slices = _s;
  limb_count = _lc;
}

Tree::~Tree() {
  for (LimbData* l : limbs) {
    delete l;
  }
  std::cout << "TREE DESTRUCTOR" << std::endl;
}

void Tree::trunk() {
  glPushMatrix();
  glBegin(GL_TRIANGLE_STRIP);
  // brown 0.627, 0.322, 0.176
  glColor3f(0.627, 0.322, 0.176);
  // glColor3f(1, 0, 0);
  float r = width / 2.0;
  for (int i = 0; i <= slices; i++) {
    float th = ((float)i / slices) * 2.0 * M_PI;
    glVertex3f(r * 0.5 * cosf(th), height, r * 0.5 * sinf(th));
    glVertex3f(r * cosf(th), 0.0, r * sinf(th));
  }
  glEnd();
  glBegin(GL_TRIANGLE_FAN);
  for (int i = 0; i <= slices; i++) {
    float th = ((float)i / slices) * 2.0 * M_PI;
    glVertex3f(r * 0.5 * cosf(th), height, r * 0.5 * sinf(th));
  }
  glEnd();
  glBegin(GL_TRIANGLE_FAN);
  for (int i = 0; i <= slices; i++) {
    float th = ((float)i / slices) * 2.0 * M_PI;
    glVertex3f(r * cosf(th), 0.0, r * sinf(th));
  }
  glEnd();
  glPopMatrix();
}

void Tree::limb(float y,
                float tilt,
                float rotation,
                float width,
                float length) {
  float r = width / 2.0;
  glPushMatrix();
  glTranslatef(0.0, y - r, 0.0);
  // rotation around trunk
  glRotatef(rotation, 0.0, 1.0, 0.0);
  // tilt down
  glRotatef(tilt, 0.0, 0.0, 1.0);
  glBegin(GL_TRIANGLE_STRIP);
  glColor3f(0.627, 0.322, 0.176);
  for (int i = 0; i <= slices; i++) {
    float th = ((float)i / slices) * 2.0 * M_PI;
    glVertex3f(r * 0.5 * cosf(th), length, r * 0.5 * sinf(th));
    glVertex3f(r * cosf(th), 0.0, r * sinf(th));
  }
  glEnd();
  glBegin(GL_TRIANGLE_FAN);
  for (int i = 0; i <= slices; i++) {
    float th = ((float)i / slices) * 2.0 * M_PI;
    glVertex3f(r * 0.5 * cosf(th), length, r * 0.5 * sinf(th));
  }
  glEnd();
  glBegin(GL_TRIANGLE_FAN);
  for (int i = 0; i <= slices; i++) {
    float th = ((float)i / slices) * 2.0 * M_PI;
    glVertex3f(r * cosf(th), 0.0, r * sinf(th));
  }
  glEnd();
  glPopMatrix();
}

void Tree::render() {
  glPushMatrix();
  glTranslatef(x, y, z);
  trunk();
  for (LimbData* l : limbs) {
    limb(l->height, l->tilt, l->rotation, l->width, l->length);
  }
  glPopMatrix();
}
