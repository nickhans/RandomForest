#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <iostream>

class Object {
 public:
  Object();
  Object(float _x, float _y, float _z, float _h, float _w);
  ~Object();

  void set_height(float);
  void set_width(float);

  void set_x(float);
  void set_y(float);
  void set_z(float);

  float get_height();
  float get_width();

  float get_x();
  float get_y();
  float get_z();

 protected:
  float height;
  float width;

  float x;
  float y;
  float z;
};

#endif
