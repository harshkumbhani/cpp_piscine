#include "PhoneBook.hpp"

std::string	to_upper(std::string& input)
{
	std::string::iterator	it;

	for (it = input.begin(); it != input.end(); it++)
		*it = std::toupper(static_cast<unsigned char>(*it));
	return input;
}

int	main(int argc, char *argv[])
{
	PhoneBook	book;
	std::string input;

	if (argc != 1){
		std::cout << "Usage: < " << argv[0] << "  >" << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Command list: <  ADD | SEARCH | EXIT  >" << std::endl;
	while (true)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (to_upper(input).compare("EXIT") == 0)
			break ;
		else if (to_upper(input).compare("ADD") == 0)
			book.newEntry();
		else if (to_upper(input).compare("SEARCH") == 0)
			book.displayContactSummary();
		else if (input.empty() == false)
			std::cout << "Invalid command! Please try again" << std::endl;
	}
	return (EXIT_SUCCESS);
}
