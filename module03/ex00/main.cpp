#include "ClapTrap.hpp"

int main(void) {
  // Initialize two ClapTrap instances with names
  ClapTrap warrior("Warrior");
  ClapTrap rogue("Rogue");

  std::cout << "---- The Arena ----\n";
  std::cout
      << "Two ClapTraps enter the arena, showcasing their combat skills.\n\n";

  // Round 1: Warrior attacks Rogue
  std::cout << "The Warrior advances, aiming a precise strike at the Rogue.\n\n";
  warrior.attack("Rogue");
  rogue.takeDamage(3); // Assuming 3 damage points for illustration
  std::cout << "┌───────────────────────────────┐\n";
  std::cout << "| Result: Rogue takes 3 damage. |\n";
  std::cout << "└───────────────────────────────┘\n\n";

  // Rogue's retaliation
  std::cout << "Quick on their feet, the Rogue counterattacks.\n\n";
  rogue.attack("Warrior");
  warrior.takeDamage(4); // Assuming 4 damage points for illustration
  std::cout << "┌─────────────────────────────────┐\n";
  std::cout << "| Result: Warrior takes 4 damage. |\n";
  std::cout << "└─────────────────────────────────┘\n\n";

  // Round 2: Repair and attack
  std::cout << "Battered but unbowed, the Warrior attempts to repair itself.\n\n";
  warrior.beRepaired(5);
  std::cout << "┌───────────────────────────────────────┐\n";
  std::cout << "| Result: Warrior repairs 5 hit points. |\n";
  std::cout << "└───────────────────────────────────────┘\n\n";

  std::cout
      << "Seeing the Warrior distracted, the Rogue launches a fierce attack.\n\n";
  rogue.attack("Warrior");
  warrior.takeDamage(5); // Assuming 5 damage points for this attack
  std::cout << "┌─────────────────────────────────┐\n";
  std::cout << "| Result: Warrior takes 5 damage. |\n";
  std::cout << "└─────────────────────────────────┘\n\n";

  // Final standoff
  std::cout << "The arena falls silent as both ClapTraps, showing signs of "
               "wear and tear, stand ready for the next round.\n";
  return 0;
}
