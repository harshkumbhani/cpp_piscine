#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
  static const int inventorySize = 4;
  static const int discardedItemSize = 128;
  std::string _name;
  int _nbEquippedItems;
  int _nbUnEquippedItems;
  AMateria *inventory[inventorySize];
  AMateria *unequippedItems[discardedItemSize];

public:
  Character();
  Character(const std::string& name);
  Character(const Character &src);
  Character &operator=(const Character &rhs);
  ~Character();

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif
