#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName(void) const { return _firstName; }

std::string Contact::getLastName(void) const { return _lastName; }

std::string Contact::getNickName(void) const { return _nickName; }

std::string Contact::getPhoneNumber(void) const { return _phoneNumber; }

std::string Contact::getDarkSecret(void) const { return _darkestSecret; }

bool Contact::processPhoneNb(const std::string &field,
                             const std::string &input) const {
  std::istringstream inputStream(input);
  long number = 0;
  if ((inputStream >> number).fail() == false && inputStream.eof() == true &&
      number >= 0) {
    return true;
  } else {
    if (number < 0)
      std::cout << "Negative " << field << " not Possible on Earth!" << std::endl;
    else if (number == std::numeric_limits<long>::max())
      std::cout << "Field " << field << " too big!!" << std::endl;
    else
      std::cout << "Non numeric character detected! Please enter valid"
                << " Phone Number." << std::endl;
    return false;
  }
}

bool  Contact::processOtherFields(const std::string &field,
                                  std::string &input) const {
  size_t  start = input.find_first_not_of(" \t\n\r\f\v\"");
  size_t  end = input.find_last_not_of(" \t\n\r\f\v\"");

  if (start == std::string::npos || end == std::string::npos)
  {
    std::cout << "Either " << field
      << " is empty or found no valid name characters."
      << std::endl;
    return false;
  }
  input = input.substr(start, end - start + 1);
  return true;
}

std::string Contact::enterFieldData(const std::string &field, int &i) const {
  bool isValid = false;
  std::string input;
  do {
    std::cout << field;
    std::getline(std::cin, input);

    if (input.empty() == true) {
      std::cout << "Field: " << field
        << " cannot be empty, Please enter a value." << std::endl;
      continue;
    }
    if (i == 3) {
      isValid = processPhoneNb(field, input);
    } else {
      isValid = processOtherFields(field, input);
    }
  } while (isValid == false);
  return input;
}

void Contact::create_new_entry() {
  const std::string fields[5] = {"First Name: ", "Last Name: ", "Nick Name: ",
                                 "Phone Number: ", "Darkest Secret: "};

  std::string *data[5] = {&_firstName, &_lastName, &_nickName, &_phoneNumber,
                          &_darkestSecret};
  std::cout << "\nEnter the details as followed\n" << std::endl;
  for (int i = 0; i < 5; i++) {
    *data[i] = enterFieldData(fields[i], i);
  }
  std::cout << "\nEntry created successfully!" << std::endl;
}
