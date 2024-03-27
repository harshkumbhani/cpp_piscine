#include "ScavTrap.hpp"

int main(void) {
    ScavTrap robot1("Humanoid");

    robot1.attack("Terminator");
    robot1.takeDamage(10);
    robot1.guardGate();

  return 0;
}
