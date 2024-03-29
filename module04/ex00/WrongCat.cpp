#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  printLog("WrongCat constructor called.", MAGENTA);
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
  printLog("WrongCat copy constructor called.", MAGENTA);
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
  printLog("WrongCat assignment operator constructor called.", MAGENTA);
  if (this != &rhs) {
    WrongAnimal::operator=(rhs);
  }
  return *this;
}

WrongCat::~WrongCat() { printLog("WrongCat destructor called.", RED); }

void WrongCat::makeSound(void) const {
  printLog("WrongCat: Meow-hiss-purr-tumble-squeak!", GREEN);
}
