#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
  Contact contacts[MAX_ENTRIES];
  unsigned int _index;
  unsigned int _currentIndex;
  std::string truncateField(std::string field) const;
  void  displayContactDetails(void) const;
public:
  PhoneBook();
  ~PhoneBook();

  void newEntry(void);
  void displayContactSummary(void) const;
};

#endif
