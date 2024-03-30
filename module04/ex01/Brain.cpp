#include "Brain.hpp"

Brain::Brain() {
  printLog("Brain constructor called.", YELLOW);
}

Brain::Brain(const Brain& src) {
  *this = src;
  printLog("Brain copy constructor called.", YELLOW);
}

Brain&  Brain::operator=(const Brain& rhs) {
  printLog("Brain assignment operator constructor called.", YELLOW);
  if (this != &rhs) {
    for (int i = 0; i < 100; i++){
      _ideas[i] = rhs._ideas[i];
    }
  }
  return *this;
}

Brain::~Brain() {
  printLog("Brain destructor called.", RED);
}

std::string Brain::getIdea(int index) const {
  --index;
  if (index >= 0 && index < 100)
    return _ideas[index];
  return "Invalid Index";
}

void  Brain::setIdea(int index, const std::string &idea) {
  --index;
  if (index >= 0 && index < 100)
    _ideas[index] = idea;
}

