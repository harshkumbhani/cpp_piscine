#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : 
  ClapTrap("Default", 100, 50, 20), _gateGuardStatus(0) {
  std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) :
  ClapTrap(name, 100, 50, 20), _gateGuardStatus(0) {
  std::cout << "ScavTrap string constructor called." << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called."<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
  std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs) {
  std::cout << "ScavTrap copy assignment operator called." << std::endl;
  if (this != &rhs) {
    ClapTrap::operator=(rhs);
  }
  return *this;
}

void  ScavTrap::attack(const std::string &target) {
  if (_energyPoints == 0) {
    std::cout << "ScavTrap " << _name << " has no energy left to attack!"
              << std::endl;
    return;
  }
  --_energyPoints;
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage" << std::endl;
}

void  ScavTrap::guardGate() {
  _gateGuardStatus = true;
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
