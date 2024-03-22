#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(void) const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese"
	"triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
			"enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
			"years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level) const
{
	int		index = -1;
	std::string	levels[L] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < L; i++)
	{
		if (levels[i].compare(level) == 0)
			index = i;
	}
	
	switch (index)
	{
	case 0:
		this->debug();
		// Intentional fallthrough
	case 1:
		this->info();
		// Intentional fallthrough
	case 2:
		this->warning();
		// Intentional fallthrough
	case 3:
		this->error();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	return ;
}

void	to_upper(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = std::toupper(str[i]);
}