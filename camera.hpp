#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "util.hpp"

class Camera {
 public:
  Camera();

  void project();
  void set_eye_position();

  double get_fov();
  double get_asp();
  double get_dim();
  double get_Ex();
  double get_Ey();
  double get_Ez();
  int get_th();
  int get_ph();

  void set_fov(double);
  void set_asp(double);
  void set_dim(double);
  void set_Ex(double);
  void set_Ey(double);
  void set_Ez(double);
  void set_th(int);
  void set_ph(int);

 private:
  // field of view, aspect ratio, dimension
  double _fov;
  double _asp;
  double _dim;

  // Eye positions
  double _Ex;
  double _Ey;
  double _Ez;

  // view angles
  int _th;
  int _ph;
};

#endif
