#include "camera.hpp"

Camera::Camera() {
  _fov = 60;
  _asp = 1;
  _dim = 10;
  _th = 0;
  _ph = 30;
  _Ex = -40 * _dim * Sin(_th) * Cos(_ph);
  _Ey = 40 * _dim * Sin(_ph);
  _Ez = 40 * _dim * Cos(_th) * Sin(_ph);
}

void Camera::project() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(_fov, _asp, _dim / 16, 16 * _dim);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Camera::set_eye_position() {
  _Ex = -2 * _dim * Sin(_th) * Cos(_ph);
  _Ey = +2 * _dim * Sin(_ph);
  _Ez = +2 * _dim * Cos(_th) * Cos(_ph);
  gluLookAt(_Ex, _Ey, _Ez, 0, 0, 0, 0, Cos(_ph), 0);
}

double Camera::get_asp() {
  return _asp;
}

double Camera::get_fov() {
  return _fov;
}

double Camera::get_dim() {
  return _dim;
}

int Camera::get_th() {
  return _th;
}

int Camera::get_ph() {
  return _ph;
}

double Camera::get_Ex() {
  return _Ex;
}

double Camera::get_Ey() {
  return _Ey;
}

double Camera::get_Ez() {
  return _Ez;
}

void Camera::set_asp(double asp) {
  _asp = asp;
}

void Camera::set_fov(double fov) {
  _fov = fov;
}

void Camera::set_dim(double dim) {
  _dim = dim;
}

void Camera::set_Ex(double Ex) {
  _Ex = Ex;
}

void Camera::set_Ey(double Ey) {
  _Ey = Ey;
}

void Camera::set_Ez(double Ez) {
  _Ez = Ez;
}

void Camera::set_th(int th) {
  _th = th % 360;
}

void Camera::set_ph(int ph) {
  _ph = ph % 360;
}
