#include "Functions.hpp"
#include "Classes.hpp"

Base *generate(void) {
  int classIdentity;
  Base *returnClass;
  static int counter = 0;

  srand(time(NULL) + ++counter);

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
  if (dynamic_cast<A *>(p) != NULL)
    std::cout << "Class: A\n" << std::endl;
  else if (dynamic_cast<B *>(p) != NULL)
    std::cout << "Class: B\n" << std::endl;
  else if (dynamic_cast<C *>(p) != NULL)
    std::cout << "Class: C\n" << std::endl;
  else
    std::cout << "Conversion not possible\n" << std::endl;
}

void identify(Base &p) {

  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "Class: A\n" << std::endl;
  } catch (std::exception &) {
  }
  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "Class: B\n" << std::endl;
  } catch (std::exception &) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "Class: C\n" << std::endl;
  } catch (std::exception &) {
  }
}
