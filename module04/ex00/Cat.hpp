#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
protected:
public:
  Cat();
  Cat(const Cat &src);
  Cat &operator=(const Cat &rhs);
  virtual ~Cat();

  virtual void makeSound(void) const;
};

#endif
