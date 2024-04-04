#include "MateriaSource.hpp"

// ===== Constructors & Destructor =====

MateriaSource::MateriaSource() : nbMaterias(0) {
  for (int i = 0; i < materiaSize; i++)
    aMateria[i] = NULL;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < materiaSize; i++) {
    if (aMateria[i] != NULL)
      delete aMateria[i];
  }
}

// ===== Copy Constructor & Copy Assignment Operator =====

MateriaSource::MateriaSource(const MateriaSource &src) {
  for (int i = 0; i < materiaSize; i++)
    aMateria[i] = NULL;
  *this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
  if (this != &rhs) {
    this->nbMaterias = rhs.nbMaterias;
    for (int i = 0; i < this->materiaSize; i++) {
      if (aMateria[i] != NULL) {
        delete this->aMateria[i];
        aMateria[i] = NULL;
      }
      if (rhs.aMateria[i] != NULL) {
        aMateria[i] = rhs.aMateria[i]->clone();
      }
    }
  }
  return *this;
}

// ===== Public Member Functions =====

void MateriaSource::learnMateria(AMateria *materia) {
  if (nbMaterias >= 4) {
    std::cout << "No more room to learn more Materias. All 4 slots filled."
              << std::endl;
    return;
  }
  std::cout << "Learning " << materia->getType() << " template." << std::endl;
  aMateria[nbMaterias] = materia->clone();
  ++nbMaterias;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i = 0; i < nbMaterias; i++) {
    if (aMateria[i] != NULL && (aMateria[i]->getType() == type))
      return aMateria[i]->clone();
  }
  return NULL;
}
