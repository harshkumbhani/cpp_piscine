#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) :
  _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point &src) : _x(src._x), _y(src._y) {}

Point& Point::operator=(const Point &rhs){
  if (this != &rhs){
    (Fixed) this->_x = rhs.getX();
    (Fixed) this->_y = rhs.getY();
  }
  return *this;
}

Fixed Point::getX(void) const{
  return this->_x;
}

Fixed Point::getY(void) const {
  return this->_y;
}

Point::~Point() {}
