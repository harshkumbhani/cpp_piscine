#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  static const int materiaSize = 4;
  int nbMaterias;
  AMateria* aMateria[materiaSize];

public:
  MateriaSource();
  MateriaSource(const MateriaSource& src);
  MateriaSource& operator=(const MateriaSource& rhs);
  ~MateriaSource();

  void  learnMateria(AMateria *);
  AMateria* createMateria(std::string const &type);
};

#endif
