#include "tree.hpp"

LimbData::LimbData() {
  height = 0.0f;
  tilt = 0.0f;
  rotation = 0.0f;
  width = 10.0f;
  length = 20.0f;
}

LimbData::LimbData(float h, float t, float r, float w, float l) {
  height = h;
  tilt = t;
  rotation = r;
  width = w;
  length = l;
}

LimbData::~LimbData() {
  // std::cout << "LIMB DESTRUCTOR" << std::endl;
}

Tree::Tree() : Object(0.0f, 0.0f, 0.0f, 5.0f, 1.0f) {
  slices = 15;
  bark_tex = UINT32_MAX;
  leaf_tex = UINT32_MAX;
}

Tree::Tree(float _x,
           float _y,
           float _z,
           float _h,
           float _w,
           int _s,
           int _lc,
           GLuint _bark,
           GLuint _leaf)
    : Object(_x, _y, _z, _h, _w) {
  std::uniform_real_distribution<float> h_dist(height * 0.2f, height);
  std::uniform_real_distribution<float> t_dist(30.0f, 80.0f);
  std::uniform_real_distribution<float> r_dist(0.0f, 359.0f);
  std::uniform_real_distribution<float> w_dist(width * 0.3f, width * 0.5f);
  std::uniform_real_distribution<float> l_dist(height * 0.2f, height * 0.4f);

  for (int i = 0; i < _lc; i++) {
    limbs.push_back(new LimbData(h_dist(rng), t_dist(rng), r_dist(rng),
                                 w_dist(rng), l_dist(rng)));
  }

  slices = _s;
  limb_count = _lc;
  bark_tex = _bark;
  leaf_tex = _leaf;
}

Tree::~Tree() {
  for (LimbData* l : limbs) {
    delete l;
  }
  // std::cout << "TREE DESTRUCTOR" << std::endl;
}

void Tree::trunk() {
  glPushMatrix();
  glBegin(GL_TRIANGLE_STRIP);
  // brown 0.627, 0.322, 0.176
  glColor3f(0.627f, 0.322f, 0.176f);
  // glColor3f(1, 0, 0);
  float r = width / 2.0f;
  float r_scale = 0.5f;
  for (int i = 0; i <= slices; i++) {
    float th = ((float)i / slices) * 2.0f * M_PI;
    glTexCoord2f((float)i / slices, height / 2.0f);
    glVertex3f(r * r_scale * cosf(th), height, r * r_scale * sinf(th));
    glNormal3f(r * r_scale * cosf(th), height, r * r_scale * sinf(th));
    glTexCoord2f((float)i / slices, 0.0f);
    glVertex3f(r * cosf(th), 0.0f, r * sinf(th));
    glNormal3f(r * cosf(th), 0.0f, r * sinf(th));
  }
  glEnd();
  glBegin(GL_TRIANGLE_FAN);
  for (int i = 0; i <= slices; i++) {
    float th = ((float)i / slices) * 2.0f * M_PI;
    glVertex3f(r * r_scale * cosf(th), height, r * r_scale * sinf(th));
    glNormal3f(0.0f, 1.0f, 0.0f);
  }
  glEnd();
  glBegin(GL_TRIANGLE_FAN);
  for (int i = 0; i <= slices; i++) {
    float th = ((float)i / slices) * 2.0f * M_PI;
    glVertex3f(r * cosf(th), 0.0, r * sinf(th));
    glNormal3f(0.0f, -1.0f, 0.0f);
  }
  glEnd();
  glPopMatrix();
}

void Tree::limb(float y,
                float tilt,
                float rotation,
                float width,
                float length) {
  float r = width / 2.0f;
  float r_scale = 0.5f;
  glPushMatrix();
  glTranslatef(0.0f, y - r, 0.0f);
  // rotation around trunk
  glRotatef(rotation, 0.0f, 1.0f, 0.0f);
  // tilt down
  glRotatef(tilt, 0.0f, 0.0f, 1.0f);
  glBegin(GL_TRIANGLE_STRIP);
  glColor3f(0.627f, 0.322f, 0.176f);
  for (int i = 0; i <= slices; i++) {
    float th = ((float)i / slices) * 2.0 * M_PI;
    glTexCoord2f((float)i / slices, length / 2.0f);
    glVertex3f(r * r_scale * cosf(th), length, r * r_scale * sinf(th));
    glNormal3f(r * r_scale * cosf(th), length, r * r_scale * sinf(th));
    glTexCoord2f((float)i / slices, 0.0f);
    glVertex3f(r * cosf(th), 0.0f, r * sinf(th));
    glNormal3f(r * cosf(th), 0.0f, r * sinf(th));
  }
  glEnd();
  glBegin(GL_TRIANGLE_FAN);
  for (int i = 0; i <= slices; i++) {
    float th = ((float)i / slices) * 2.0f * M_PI;
    glVertex3f(r * r_scale * cosf(th), length, r * r_scale * sinf(th));
    glNormal3f(0.0f, 1.0f, 0.0f);
  }
  glEnd();
  glBegin(GL_TRIANGLE_FAN);
  for (int i = 0; i <= slices; i++) {
    float th = ((float)i / slices) * 2.0f * M_PI;
    glVertex3f(r * cosf(th), 0.0f, r * sinf(th));
    glNormal3f(0.0f, -1.0f, 0.0f);
  }
  glEnd();

  leaves(length, width);

  glPopMatrix();
}

void Tree::leaves(float length, float width) {
  glDisable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glBindTexture(GL_TEXTURE_2D, leaf_tex);
  for (int i = 0; i < 180; i += 180 / 5) {
    glPushMatrix();
    glRotatef(i, 0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor4f(0.0f, 0.0f, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(width * 2.0f, 0.0f, 0.0f);

    glTexCoord2f(1.0f, length * 1.5f);
    glVertex3f(width * 2.0f, length * 1.1f, 0.0f);

    glTexCoord2f(-1.0f, length * 1.5f);
    glVertex3f(-width * 2.0f, length * 1.1f, 0.0f);

    glTexCoord2f(-1.0f, 0.0f);
    glVertex3f(-width * 2.0f, 0.0f, 0.0f);

    glEnd();
    glPopMatrix();
  }
  glDisable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
}

void Tree::render() {
  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glPushMatrix();
  glTranslatef(x, y, z);
  glBindTexture(GL_TEXTURE_2D, bark_tex);
  trunk();
  for (LimbData* l : limbs) {
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, bark_tex);
    limb(l->height, l->tilt, l->rotation, l->width, l->length);
  }
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}
