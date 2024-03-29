#include "Dog.hpp"

Dog::Dog() : Animal("Dog") { printLog("Dog constructor called.", MAGENTA); }

Dog::Dog(const Dog &src) : Animal(src) {
  printLog("Dog copy constructor called.", MAGENTA);
}

Dog &Dog::operator=(const Dog &rhs) {
  printLog("Dog assignment operator constructor called.", MAGENTA);
  if (this != &rhs) {
    Animal::operator=(rhs);
  }
  return *this;
}

Dog::~Dog() { printLog("Dog destructor called.", RED); }

void Dog::makeSound(void) const {
  printLog("Dog: Woof-haha-snorf-snorf-grrr-woooooof!", GREEN);
}
