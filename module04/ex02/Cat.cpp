#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
  printLog("Cat constructor called.", MAGENTA);
}

Cat::Cat(const Cat &src) : AAnimal(src), _brain(new Brain(*(src._brain))) {
  printLog("Cat copy constructor called.", MAGENTA);
}

Cat &Cat::operator=(const Cat &rhs) {
  printLog("Cat assignment operator constructor called.", MAGENTA);
  if (this != &rhs) {
    _type = rhs._type;
    *_brain = *(rhs._brain);
  }
  return *this;
}

Cat::~Cat() {
  delete _brain;
  printLog("Cat destructor called.", RED);
}

void Cat::makeSound(void) const {
  printLog("Cat: Meow-hiss-purr-tumble-squeak!", GREEN);
}

std::string Cat::getIdea(int index) const { return _brain->getIdea(index); }

void Cat::setIdea(int index, const std::string &idea) {
  _brain->setIdea(index, idea);
}

void Cat::printIdeas(void) const { _brain->printIdeas(); }
