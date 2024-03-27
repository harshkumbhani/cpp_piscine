#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name", 100, 50, 30), FragTrap("DefaultFrag"),
      ScavTrap("DefaultScav") {
  _name = "DefaultDiamond";
  ClapTrap::_name = _name + "_clap_name";
  std::cout << "DiamondTrap deafault constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name)
    : ClapTrap(name + "_clap_name", 100, 50, 30), FragTrap(name),
      ScavTrap(name), _name(name) {
  ClapTrap::_name = name + "_clap_name";
  std::cout << "DiamondTrap string constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
    : ClapTrap(src._name + "_clap_name", src._hitPoints, src._energyPoints,
               src._attackDamage),
      FragTrap(src), ScavTrap(src), _name(src._name) {
  ClapTrap::_name = src._name + "_clap_name";
  std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
  std::cout << "Diamond copy assignment operator called." << std::endl;
  if (this != &rhs) {
    _name = rhs._name;
    FragTrap::operator=(rhs);
    ScavTrap::operator=(rhs);
    ClapTrap::_name = rhs.ClapTrap::_name;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called." << std::endl;
}

void DiamondTrap::whoAmI() {
  std::cout << "Diamond Trap name: " << _name << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}
