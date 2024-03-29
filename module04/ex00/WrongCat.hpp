
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
protected:
public:
  WrongCat();
  WrongCat(const WrongCat &src);
  WrongCat &operator=(const WrongCat &rhs);
  virtual ~WrongCat();

  void makeSound(void) const;
};

#endif
