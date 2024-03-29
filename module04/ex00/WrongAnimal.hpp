#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal {
protected:
  std::string _type;

public:
  WrongAnimal();
  WrongAnimal(std::string type);
  WrongAnimal(const WrongAnimal &src);
  WrongAnimal &operator=(const WrongAnimal &rhs);
  virtual ~WrongAnimal();

  std::string getType(void) const;
  void makeSound(void) const;
};

#endif
