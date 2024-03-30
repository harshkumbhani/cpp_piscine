#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain*  _brain;
public:
  Dog();
  Dog(const Dog &src);
  Dog &operator=(const Dog &rhs);
  virtual ~Dog();

  virtual void makeSound(void) const;
  std::string getIdea(int index) const;
  void  setIdea(int index, const std::string& idea);
};

#endif
