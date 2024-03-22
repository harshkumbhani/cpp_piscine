
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>

#define	MAX_ENTRIES	8

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact();
	~Contact();

	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickName(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkSecret(void) const;
	void	create_new_entry(void);
};

#endif
