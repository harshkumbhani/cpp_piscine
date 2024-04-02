#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
private:
public:
  Ice();
  Ice(const Ice &src);
  Ice &operator=(const Ice &rhs);
  virtual ~Ice();

  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif
