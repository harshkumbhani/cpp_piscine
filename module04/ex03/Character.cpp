#include "Character.hpp"

// ===== Constructors & Destructor =====

Character::Character()
    : _name("Oreste"), _nbEquippedItems(0), _nbUnEquippedItems(0) {
  for (int i = 0; i < inventorySize; i++)
    inventory[i] = NULL;
  for (int i = 0; i < discardedItemSize; i++)
    unequippedItems[i] = NULL;
}

Character::Character(const std::string &name)
    : _name(name), _nbEquippedItems(0), _nbUnEquippedItems(0) {
  for (int i = 0; i < inventorySize; i++)
    inventory[i] = NULL;
  for (int i = 0; i < discardedItemSize; i++)
    unequippedItems[i] = NULL;
}

Character::~Character() {
  for (int i = 0; i < inventorySize; i++) {
    if (inventory[i] != NULL) {
      delete inventory[i];
      inventory[i] = NULL;
    }
  }
  for (int i = 0; i < discardedItemSize; i++) {
    if (unequippedItems[i] != NULL) {
      delete unequippedItems[i];
      unequippedItems[i] = NULL;
    }
  }
}

// ===== Copy Constructor & Copy Assignment Operator =====

Character::Character(const Character &src) {
  for (int i = 0; i < inventorySize; i++)
    inventory[i] = NULL;
  for (int i = 0; i < discardedItemSize; i++)
    unequippedItems[i] = NULL;
  *this = src;
}

Character &Character::operator=(const Character &rhs) {
  if (this != &rhs) {
    this->_name = rhs._name;
    this->_nbEquippedItems = rhs._nbEquippedItems;
    this->_nbUnEquippedItems = rhs._nbUnEquippedItems;
    for (int i = 0; i < this->inventorySize; i++) {
      if (this->inventory[i] != NULL) {
        delete this->inventory[i];
        this->inventory[i] = NULL;
      }
      if (rhs.inventory[i] != NULL)
        this->inventory[i] = rhs.inventory[i]->clone();
    }
    for (int i = 0; i < this->discardedItemSize; i++) {
      if (this->unequippedItems[i] != NULL) {
        delete this->unequippedItems[i];
        this->unequippedItems[i] = NULL;
      }
      if (rhs.unequippedItems[i] != NULL)
        this->unequippedItems[i] = rhs.unequippedItems[i]->clone();
    }
  }
  return *this;
}

// ===== Public Member Functions =====

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
  if (m == NULL) {
    std::cout << "Cannot equip NULL materia!" << std::endl;
    return;
  }

  if (this->_nbEquippedItems >= inventorySize) {
    std::cout << "Inventory FULL ! Item cannot be equipped." << std::endl;
    delete m;
    return;
  }

  inventory[_nbEquippedItems] = m->clone();
  ++this->_nbEquippedItems;
  std::cout << this->getName() << " equipes " << m->getType() << std::endl;
  delete m;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= this->inventorySize) {
    std::cout << "Item out of bounds! Enter item index between 0 and "
              << _nbEquippedItems << std::endl;
    return;
  }

  if (inventory[idx] == NULL) {
    std::cout << "Error ! Trying to unequip empty slot." << std::endl;
    return;
  }

  std::cout << this->_name << " unequips " << inventory[idx]->getType()
            << std::endl;
  unequippedItems[_nbUnEquippedItems] = inventory[idx];
  inventory[idx] = NULL;
  --_nbEquippedItems;
  ++_nbUnEquippedItems;

  for (int i = idx; i < _nbEquippedItems; i++)
    inventory[i] = inventory[i + 1];

  inventory[_nbEquippedItems] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || idx >= inventorySize) {
    std::cout << "Item out of bounds! Enter item index between 0 and "
              << _nbEquippedItems << std::endl;
    return;
  }

  if (inventory[idx] == NULL) {
    std::cout << "Error ! Trying to unequip empty slot." << std::endl;
    return;
  }

  inventory[idx]->use(target);
}
