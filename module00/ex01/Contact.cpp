#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName(void) const { return _firstName; }

std::string Contact::getLastName(void) const { return _lastName; }

std::string Contact::getNickName(void) const { return _nickName; }

std::string Contact::getPhoneNumber(void) const { return _phoneNumber; }

std::string Contact::getDarkSecret(void) const { return _darkestSecret; }

std::string Contact::enterFieldData(const std::string &field, int &i) const {
  bool isValid = false;
  std::string input;
  do {
    std::cout << field;
    std::getline(std::cin, input);
    if (i == 3) {
      std::istringstream inputStream(input);
      long number;
      inputStream >> number;
      if (inputStream.fail() == false && inputStream.eof() == true &&
          number >= 0) {
        isValid = true;
      } else {
        if (number < 0)
          std::cout << field << "cannot be Negative!" << std::endl;
        else if (number == std::numeric_limits<long>::max())
          std::cout << "Max limit for digits reached! Retry" << std::endl;
        else
          std::cout << "Non numeric character detected! Please enter valid"
                    << " Phone Number." << std::endl;
        isValid = false;
      }
    } else {
      std::string::iterator it;
      isValid = input.empty() == false &&
                input.find_last_not_of(" \n\t\v\f\r") != std::string::npos;
      if (input.compare("\"\"") == 0) {
        isValid = false;
        std::cout << field << "cannot be an empty." << std::endl;
      } else if (input[0] == '\"' && input[input.length() - 1] == '\"') {
        input = input.substr(1, input.length() - 2);
      } else {
        for (it = input.begin(); it != input.end(); it++) {
          if (*it == '\"') {
            std::cout << "Illegal use of \" character detected or trailing"
                      << " spaces / characters after \"" << std::endl;
            isValid = false;
            break;
          }
        }
      }
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
