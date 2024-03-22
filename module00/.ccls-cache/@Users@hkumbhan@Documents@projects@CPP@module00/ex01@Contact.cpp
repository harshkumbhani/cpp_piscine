#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string	Contact::getFirstName(void) const
{
	return _firstName;
}

std::string	Contact::getLastName(void) const
{
	return _lastName;
}

std::string	Contact::getNickName(void) const
{
	return _nickName;
}

std::string	Contact::getPhoneNumber(void) const
{
	return _phoneNumber;
}

std::string	Contact::getDarkSecret(void) const
{
	return _darkestSecret;
}

void	Contact::create_new_entry(){
	const std::string	fields[5] = {
		"First Name: ",
		"Last Name: ",
		"Nick Name: ",
		"Phone Number: ",
		"Darkest Secret: "
	};

	std::string	*data[5] = {
		&_firstName,
		&_lastName,
		&_nickName,
		&_phoneNumber,
		&_darkestSecret
	};
	std::cout << "\nEnter the details as followed\n" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::string	input;
		do {
			std::cout << fields[i];
			std::getline(std::cin, input);
		} while (input.find_last_not_of(" \n\t\v\f\r") == std::string::npos);
		*data[i] = input;
	}
	std::cout << std::endl;
}
