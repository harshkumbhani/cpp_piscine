#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLD    "\033[1m"       /* Bold text */
#define UNDERLINE "\033[4m"    /* Underlined text */

class ClapTrap {
protected:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

public:
  ClapTrap();
  ClapTrap(const std::string name);
  ClapTrap(const std::string name, unsigned int, unsigned int, unsigned int);
  ClapTrap(const ClapTrap &src);
  ClapTrap &operator=(const ClapTrap &rhs);
  ~ClapTrap();

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
