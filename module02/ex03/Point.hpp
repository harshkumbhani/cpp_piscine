#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

const std::string RED = "\033[31m";    // For critical information
const std::string YELLOW = "\033[33m"; // For important points
const std::string GREEN = "\033[32m";  // For positive outcomes
const std::string CYAN = "\033[36m";   // For informational text
const std::string RESET = "\033[0m";   // Reset to default terminal color

class Point {

private:
  const Fixed _x;
  const Fixed _y;

public:
  Point();
  Point(const float x, const float y);
  Point(const Point &src);
  Point &operator=(const Point &rhs);
  ~Point();

  Fixed getX(void) const;
  Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
