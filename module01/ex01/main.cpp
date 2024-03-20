#include "Zombie.hpp"

#define N 5

int	main(void)
{
	Zombie*   horde;

	std::cout << "=================================================" << std::endl;
	std::cout << "||             ~ Zombie Horde Awakens ~        ||" << std::endl;
	std::cout << "=================================================" << std::endl;
	horde = zombieHorde(N, "Crazy");
	std::cout << "=================================================" << std::endl;
	std::cout << "||           ~ Announcing The Horde ~          ||" << std::endl;
	std::cout << "=================================================" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << "=> Zombie #" << i + 1 << " steps forward:" << std::endl;
		horde[i].announce();
	}
	std::cout << "=================================================" << std::endl;
	std::cout << "||             ~ Disbanding The Horde ~        ||" << std::endl;
	std::cout << "=================================================" << std::endl;
	delete [] horde;
	return (0);
}
