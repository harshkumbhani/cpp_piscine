#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
	bool _gateGuardStatus;
public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &src);
  ScavTrap &operator=(const ScavTrap &rhs);
  ~ScavTrap();

  void guardGate();
	void attack(const std::string &target);
};

#endif
