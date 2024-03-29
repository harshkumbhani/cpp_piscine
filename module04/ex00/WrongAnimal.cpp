#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
  printLog("WrongAnimal constructor called.", YELLOW);
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
  printLog("WrongAnimal string constructor called.", YELLOW);
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src._type) {
  printLog("WrongAnimal copy constructor called.", YELLOW);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  printLog("WrongAnimal assignment operator constructor called.", YELLOW);
  if (this != &rhs) {
    _type = rhs._type;
  }
  return *this;
}

WrongAnimal::~WrongAnimal() { printLog("WrongAnimal destructor called.", RED); }

std::string WrongAnimal::getType(void) const { return _type; }

void WrongAnimal::makeSound(void) const {
  printLog("Wrong WrongAnimal: making WROOOOOOOOOONG sounds!", GREEN);
}
