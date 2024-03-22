/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:23:47 by hkumbhan          #+#    #+#             */
/*   Updated: 2024/03/19 17:59:46 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[]) {
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else {
    for (int i = 1; i < argc; i++) {
      std::string arg_string(argv[i]);

      std::string::iterator it;
      for (it = arg_string.begin(); it != arg_string.end(); ++it)
        *it = std::toupper(*it);
      std::cout << arg_string;
    }
  }
  std::cout << std::endl;
  return (0);
}
