#include "Functions.hpp"
#include "Classes.hpp"

badCast::badCast(const std::string &msg) : std::runtime_error(msg){};

Base *generate(void) {
  int classIdentity;
  Base *returnClass;

  srand(time(NULL));
  classIdentity = rand() % 3;

  switch (classIdentity) {
  case 0:
    returnClass = new A;
    break;
  case 1:
    returnClass = new B;
    break;
  case 2:
    returnClass = new C;
    break;
  default:
    returnClass = NULL;
    break;
  }

  return returnClass;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p) != 0)
    std::cout << "Class: A\n" << std::endl;
  else if (dynamic_cast<B *>(p) != 0)
    std::cout << "Class: B\n" << std::endl;
  else if (dynamic_cast<C *>(p) != 0)
    std::cout << "Class: C\n" << std::endl;
  else
    std::cout << "Conversion not possible\n" << std::endl;
}

void identify(Base &p) {

  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "Class: A\n" << std::endl;
  } catch (std::bad_cast &) {
    try {
      B &b = dynamic_cast<B &>(p);
      (void)b;
      std::cout << "Class: B\n" << std::endl;
    } catch (std::bad_cast &) {
      try {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "Class: C\n" << std::endl;
      } catch (std::bad_cast &) {
        throw badCast("std:: bad cast");
      }
    }
  }
}
