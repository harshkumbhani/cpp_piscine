#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30) {
  std::cout << "FragTrap Default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
  std::cout << "FragTrap string constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
  std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
  std::cout << "FragTrap copy assignment constructor called." << std::endl;
  if (this != &rhs)
    ClapTrap::operator=(rhs);
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called." << std::endl;
}

void FragTrap::highFiveGuys(void) {
  std::cout << "FragTrap eagerly requests, 'High five! ✋ Positive vibes only!'"
            << std::endl;
}
