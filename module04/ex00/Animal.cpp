#include "Animal.hpp"

void printLog(const std::string &message, const std::string &color) {
  std::cout << color << message << RESET << std::endl;
}

Animal::Animal() : _type("Penguin") {
  printLog("Animal constructor called.", CYAN);
}

Animal::Animal(std::string type) : _type(type) {
  printLog("Animal string constructor called.", CYAN);
}

Animal::Animal(const Animal &src) : _type(src._type) {
  printLog("Animal copy constructor called.", CYAN);
}

Animal &Animal::operator=(const Animal &rhs) {
  printLog("Animal assignment operator constructor called.", CYAN);
  if (this != &rhs) {
    _type = rhs._type;
  }
  return *this;
}

Animal::~Animal() { printLog("Animal destructor called.", RED); }

std::string Animal::getType(void) const { return _type; }

void Animal::makeSound(void) const {
  printLog("Penguin: Flap-flap-waddle-waddle-noot-noot-giggle!", GREEN);
}
