#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Default constructor" << std::endl;
	return ;
}

Zombie::~Zombie(void){
	std::cout << this->name << ": Default destructor" << std::endl;
	return ;
}

void	Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}