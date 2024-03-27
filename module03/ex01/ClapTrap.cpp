#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap Deafault constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap string constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string name, unsigned int hit,
                   unsigned int energy, unsigned int attack)
    : _name(name), _hitPoints(hit), _energyPoints(energy),
      _attackDamage(attack) {
  std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap Destructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
    : _name(src._name), _hitPoints(src._hitPoints),
      _energyPoints(src._energyPoints), _attackDamage(src._attackDamage) {
  std::cout << "ClapTrap Copy constructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
  std::cout << "Claptrap copy assignment operator called" << std::endl;
  if (this != &rhs) {
    //_name = rhs._name;
    _hitPoints = rhs._hitPoints;
    _energyPoints = rhs._energyPoints;
    _attackDamage = rhs._attackDamage;
  }
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (_energyPoints == 0) {
    std::cout << "Claptrap " << _name << " has no energy left to attack!"
              << std::endl;
    return;
  }
  --_energyPoints;
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << "ClapTrap " << _name << "cannot take any damage,"
              << " it is already down!" << std::endl;
    return;
  }
  if (amount >= _hitPoints) {
    _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " has been defeated after taking "
              << amount << " damage!" << std::endl;
  } else {
    _hitPoints -= amount;
    std::cout << "ClapTrap: " << _name << " takes " << amount
              << " damage, remaining hit points " << _hitPoints << "."
              << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints == 0) {
    std::cout << "ClapTrap: " << _name
              << " has no energy left to repair itself!" << std::endl;
    return;
  }
  --_energyPoints;
  _hitPoints += amount;
  std::cout << "ClapTrap: " << _name << " repaits itslef, restoring " << amount
            << " hitpoints, new total: " << _hitPoints << std::endl;
}
