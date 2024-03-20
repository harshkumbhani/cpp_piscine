/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:45:43 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/20 08:01:42 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap_zombie_1;
	Zombie	*heap_zombie_2;
	
	std::cout << "Heap Zombies" << std::endl;
	heap_zombie_1 = newZombie("Zombie 1");
	heap_zombie_2 = newZombie("Zombie 2");

	std::cout << "\n\n\n\n";

	std::cout << "Stack Zombies" << std::endl;
	randomChump("Stack Zombie 1");
	randomChump("Stack Zombie 2");
	delete heap_zombie_1;
	delete heap_zombie_2;
	return (0);
}

