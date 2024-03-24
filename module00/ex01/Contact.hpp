
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#define MAX_ENTRIES 8

class Contact {
private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickName;
  std::string _phoneNumber;
  std::string _darkestSecret;
  std::string enterFieldData(const std::string &field, int &i) const;
  bool processPhoneNb(const std::string &field, const std::string &input) const;
  bool processOtherFields(const std::string &field,
                          std::string &input) const;

public:
  Contact();
  ~Contact();

  std::string getFirstName(void) const;
  std::string getLastName(void) const;
  std::string getNickName(void) const;
  std::string getPhoneNumber(void) const;
  std::string getDarkSecret(void) const;
  void create_new_entry(void);
};

#endif
