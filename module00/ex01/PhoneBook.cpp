#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _index(0), _currentIndex(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::newEntry(void) {
  if (_index == std::numeric_limits<unsigned int>::max()) {
    std::cout << "Index reset to prevent overflow." << std::endl;
    _index = MAX_ENTRIES;
  }
  contacts[_index % MAX_ENTRIES].create_new_entry();
  _index++;
  if (_index <= MAX_ENTRIES) {
    std::cout << "Adding contact at index: " << _index << std::endl;
    _currentIndex = _index;
  } else {
    std::cout << "Replacing contact at index " << (_index % MAX_ENTRIES)
              << " with new contact." << std::endl;
    _currentIndex = MAX_ENTRIES;
  }
}

void PhoneBook::displayContactSummary(void) const {
  if (_currentIndex == 0) {
    std::cout << "No Contacts found! Add some to the phonebook!" << std::endl;
    return;
  }
  std::cout << "|-------------------------------------------|\n"
            << "|" << std::setw(10) << "Index"
            << "|" << std::setw(10) << "First Name"
            << "|" << std::setw(10) << "Last Name"
            << "|" << std::setw(10) << "Nick Name"
            << "|\n"
            << "|-------------------------------------------|" << std::endl;

  for (size_t i = 0; i < _currentIndex; i++) {
    std::cout << "|" << std::setw(10) << i + 1 << "|" << std::setw(10)
              << truncateField(contacts[i].getFirstName()) << "|"
              << std::setw(10) << truncateField(contacts[i].getLastName())
              << "|" << std::setw(10)
              << truncateField(contacts[i].getNickName()) << "|" << std::endl;
  }
  std::cout << "|-------------------------------------------|" << std::endl;
  displayContactDetails();
}

std::string PhoneBook::truncateField(std::string field) const {
  if (field.length() > 9)
    return field.substr(0, 9) + '.';
  return field;
}

void PhoneBook::displayContactDetails(void) const {
  unsigned int index;
  std::string inputLine;
  bool validInputFlag = false;

  while (validInputFlag == false) {
    std::cout << "Enter the index of the contact to display: ";
    std::getline(std::cin, inputLine);
    std::istringstream inputStream(inputLine);

    if (inputStream >> index && inputStream.eof()) {
      if (index >= 1 && index <= _currentIndex)
        validInputFlag = true;
      else
        std::cout << "Invalid Input! Please enter a number between 1 and "
                  << _currentIndex << std::endl;
    } else
      std::cout << "Invalid Input! Please enter a numeric value.\n";
  }
  index -= 1;

  std::cout << "\n|-----------------Contact-Details-------------------|\n"
            << std::setw(17) << "First Name: " << contacts[index].getFirstName()
            << "\n"
            << std::setw(17) << "Second Name: " << contacts[index].getLastName()
            << "\n"
            << std::setw(17) << "Nick Name: " << contacts[index].getNickName()
            << "\n"
            << std::setw(17)
            << "Phone Number: " << contacts[index].getPhoneNumber() << "\n"
            << std::setw(17)
            << "Darkest Secret: " << contacts[index].getDarkSecret()
            << "\n|---------------------------------------------------|\n";
  std::cout << std::endl;
}
