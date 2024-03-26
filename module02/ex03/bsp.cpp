#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p) {

  const Fixed d = ((b.getX() - a.getX()) * (c.getY() - a.getY())) -
                  ((c.getX() - a.getX()) * (b.getY() - a.getY()));
  const Fixed wb = (((a.getX() - c.getX()) * (p.getY() - c.getY())) -
                    ((p.getX() - c.getX()) * (a.getY() - c.getY()))) /
                   d;
  const Fixed wc = ((b.getX() - a.getX()) * (p.getY() - a.getY()) -
                    ((b.getY() - a.getY()) * (p.getX() - a.getX()))) /
                   d;
  const Fixed wa = Fixed(1) - wb - wc;
  std::cout << "\n α: " << wa << std::endl
            << " β: " << wb << std::endl
            << " γ: " << wc << std::endl;
  return wa > Fixed(0) && wa < Fixed(1) && wb > Fixed(0) && wb < Fixed(1) &&
         wc > Fixed(0) && wc < Fixed(1);
}
