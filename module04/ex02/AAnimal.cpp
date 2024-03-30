#include "AAnimal.hpp"

void printLog(const std::string &message, const std::string &color) {
  std::cout << color << message << RESET << std::endl;
}

AAnimal::AAnimal() : _type("Penguin") {
  printLog("AAnimal constructor called.", CYAN);
}

AAnimal::AAnimal(std::string type) : _type(type) {
  printLog("AAnimal string constructor called.", CYAN);
}

AAnimal::AAnimal(const AAnimal &src) : _type(src._type) {
  printLog("AAnimal copy constructor called.", CYAN);
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
  printLog("AAnimal assignment operator constructor called.", CYAN);
  if (this != &rhs) {
    _type = rhs._type;
  }
  return *this;
}

AAnimal::~AAnimal() { printLog("AAnimal destructor called.", RED); }

std::string AAnimal::getType(void) const { return _type; }

void AAnimal::makeSound(void) const {
  printLog("Penguin: Flap-flap-waddle-waddle-noot-noot-giggle!", GREEN);
}
