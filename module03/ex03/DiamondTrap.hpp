#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
  std::string _name;

public:
  DiamondTrap();
  DiamondTrap(const std::string name);
  DiamondTrap(const DiamondTrap &src);
  DiamondTrap &operator=(const DiamondTrap &rhs);
  ~DiamondTrap();

  void whoAmI() ;
  void attack(const std::string &target);
};

#endif
