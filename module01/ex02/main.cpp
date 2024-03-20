#include <iostream>

int	main(void)
{
	const std::string string = "HI THIS IS BRAIN";
	const std::string *stringPTR = &string;
	const std::string &stringREF = string;

	std::cout << "Memory Representation:\n\n";

	std::cout << "    [string]        [stringPTR]      [stringREF]\n";
	std::cout << "      |                |                 |\n";
	std::cout << "      |                |                 |\n";
	std::cout << "      V                V                 |\n";
	std::cout << "  +--------+        +--------+         +--------+\n";
	std::cout << "  |        |        | Address|         | Alias  |\n";
	std::cout << "  |  \"HI   |<-------|  of    |         | for    |\n";
	std::cout << "  |  THIS  |        | string |         | string |\n";
	std::cout << "  |  IS    |        +--------+         +--------+\n";
	std::cout << "  |  BRAIN\"|\n";
	std::cout << "  |        |\n";
	std::cout << "  +--------+\n\n";	
	std::cout << "Details:\n\n";
	std::cout << "&string: " << &string << std::endl;
	std::cout << "stringPTR:      " << stringPTR << std::endl;
	std::cout << "stringREF:      " << &stringREF << std::endl;
	std::cout << "\nValues:\n\n";
	std::cout << "string:     \"" << string << "\"\n";
	std::cout << "stringPTR:  \"" << *stringPTR << "\"\n";
	std::cout << "stringREF:  \"" << stringREF << "\"\n";
	return (0);
}
