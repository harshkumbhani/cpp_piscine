/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:18:54 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/19 17:27:00 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string input;

	while (1)
	{
		std::cin >> input;
		if (input == "EXIT")
			break ;
	}
	return (EXIT_SUCCESS);
}