#include "object.hpp"

Object::Object() {
  x = 0;
  y = 0;
  z = 0;
  height = 1;
  width = 1;
}

Object::Object(float _x, float _y, float _z, float _h, float _w) {
  x = _x;
  y = _y;
  z = _z;
  height = _h;
  width = _w;
}

Object::~Object() {
  // std::cout << "OBJECT DESTRUCTOR" << std::endl;
}

void Object::set_height(float h) {
  height = h;
}

void Object::set_width(float w) {
  width = w;
}

void Object::set_x(float a) {
  x = a;
}

void Object::set_y(float b) {
  y = b;
}

void Object::set_z(float c) {
  z = c;
}

float Object::get_height() {
  return height;
}
float Object::get_width() {
  return width;
}
float Object::get_x() {
  return x;
}
float Object::get_y() {
  return y;
}
float Object::get_z() {
  return z;
}
