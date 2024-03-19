/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:23:47 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/19 16:16:39 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//#include <ctype.h>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg_string(argv[i]);
			
			for (size_t j = 0; j < arg_string.length(); j++)
				arg_string[j] = std::toupper(arg_string[j]);
			std::cout << arg_string;
		}
	}
	std::cout << std::endl;
	return (0);
}
