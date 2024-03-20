/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:45:43 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/20 09:00:40 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap_zombie_1;
	Zombie	*heap_zombie_2;
	
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "         Creating zombies on the stack           " << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	randomChump("Random Stack Zombie 1");
	randomChump("Random Stack Zombie 1");
	std::cout << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "         Creating a zombie on the heap           " << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << std::endl;
	heap_zombie_1 = newZombie("First heap zombie");
	heap_zombie_1->announce();
	heap_zombie_2 = newZombie("Second heap zombie");
	heap_zombie_2->announce();
	std::cout << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "         Deleting zombies on the heap            " << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	delete heap_zombie_1;
	delete heap_zombie_2;
	return EXIT_SUCCESS;
	return (0);
}

