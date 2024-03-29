#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain) {
  printLog("Dog constructor called.", MAGENTA);
}

Dog::Dog(const Dog &src) : Animal(src) {
  _brain = new Brain(*(src._brain));
  printLog("Dog copy constructor called.", MAGENTA);
}

Dog &Dog::operator=(const Dog &rhs) {
  printLog("Dog assignment operator constructor called.", MAGENTA);
  if (this != &rhs) {
    _type = rhs._type;
    *_brain = *(rhs._brain);
  }
  return *this;
}

Dog::~Dog() { printLog("Dog destructor called.", RED); }

void Dog::makeSound(void) const {
  printLog("Dog: Woof-haha-snorf-snorf-grrr-woooooof!", GREEN);
}
