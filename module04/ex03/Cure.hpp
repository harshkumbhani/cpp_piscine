#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
private:
public:
  Cure();
  Cure(const Cure &src);
  Cure &operator=(const Cure &rhs);
  virtual ~Cure();

  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif
