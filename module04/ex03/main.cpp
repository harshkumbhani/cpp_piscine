#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {

  std::cout << "\n+---------------------------------------+\n";
  std::cout << "|                Config                 |\n";
  std::cout << "+---------------------------------------+\n";
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  std::cout << "\n+---------------------------------------+\n";
  std::cout << "|       Basic Equipment and Usage       |\n";
  std::cout << "+---------------------------------------+\n";
  ICharacter *hero = new Character("Hero");
  AMateria *tmp;

  tmp = src->createMateria("ice");
  hero->equip(tmp);

  tmp = src->createMateria("cure");
  hero->equip(tmp);

  tmp = src->createMateria("cure");
  hero->equip(tmp);
  tmp = src->createMateria("ice");
  hero->equip(tmp);
  tmp = src->createMateria("ice");
  hero->equip(tmp);
  tmp = src->createMateria("cure");
  hero->equip(tmp);

  ICharacter *monster = new Character("Monster");
  hero->use(0, *monster); // Should output using ice on Monster
  hero->use(2, *monster); // Should output using cure on Monster
  hero->use(-5, *monster);

  std::cout << "\n+---------------------------------------+\n";
  std::cout << "|          Copy Constructor Test        |\n";
  std::cout << "+---------------------------------------+\n";
  Character *heroCopy = new Character(*dynamic_cast<Character *>(hero));
  heroCopy->use(0, *monster); // Should output using ice on Monster
  heroCopy->use(1, *monster); // Should output using cure on Monster

  std::cout << "\n+---------------------------------------+\n";
  std::cout << "|       Assignment Operator Test        |\n";
  std::cout << "+---------------------------------------+\n";
  Character *anotherHero = new Character("AnotherHero");
  *anotherHero = *heroCopy;      // Use assignment operator
  anotherHero->use(0, *monster); // Should output using ice on Monster
  anotherHero->use(1, *monster); // Should output using cure on Monster

  std::cout << "\n+---------------------------------------+\n";
  std::cout << "|       Unequip and Re-equip Test       |\n";
  std::cout << "+---------------------------------------+\n";
  anotherHero->unequip(0); // Unequip ice
  tmp = src->createMateria("cure");
  anotherHero->equip(tmp);       // Re-equip a new ice
  anotherHero->use(0, *monster); // Should output using ice on Monster
  anotherHero->unequip(5);

  std::cout << "\n+---------------------------------------+\n";
  std::cout << "|       Destruction and Cleanup Test    |\n";
  std::cout << "+---------------------------------------+\n";
  delete hero;
  delete heroCopy;
  delete anotherHero;
  delete monster;
  delete src;

  std::cout << std::endl;
  return 0;
}
