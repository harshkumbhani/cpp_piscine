#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type){};

AMateria::AMateria(const AMateria &src) : _type(src._type) {}

AMateria &AMateria::operator=(const AMateria &rhs) {
  if (this != &rhs) {
    _type = rhs._type;
  }
  return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) {
  std::cout << "Cannot use abstract 'use' function on " << target.getName()
            << std::endl;
}
