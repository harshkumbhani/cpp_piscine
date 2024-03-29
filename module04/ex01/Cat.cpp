#include "Cat.hpp"

Cat::Cat() : Animal("Cat") { printLog("Cat constructor called.", MAGENTA); }

Cat::Cat(const Cat &src) : Animal(src) {
  printLog("Cat copy constructor called.", MAGENTA);
}

Cat &Cat::operator=(const Cat &rhs) {
  printLog("Cat assignment operator constructor called.", MAGENTA);
  if (this != &rhs) {
    Animal::operator=(rhs);
  }
  return *this;
}

Cat::~Cat() { printLog("Cat destructor called.", RED); }

void Cat::makeSound(void) const {
  printLog("Cat: Meow-hiss-purr-tumble-squeak!", GREEN);
}
