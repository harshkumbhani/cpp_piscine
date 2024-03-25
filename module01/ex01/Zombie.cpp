#include "Zombie.hpp"

Zombie::Zombie() {
  std::cout << "Default Zombie"
            << ": is Born" << std::endl;
}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie(void) {
  std::cout << this->name << ": Died" << std::endl;
  return;
}

void Zombie::announce(void) const {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
  return;
}

void Zombie::setName(std::string name) { this->name = name; }
