#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"  // Wrong Animal
#define BLUE "\033[1;34m"    // Animal
#define MAGENTA "\033[1;35m" // Cat
#define CYAN "\033[1;36m"    // Dog
#define GREEN "\033[1;32m"

class Animal {
protected:
  std::string _type;

public:
  Animal();
  Animal(std::string type);
  Animal(const Animal &src);
  Animal &operator=(const Animal &rhs);
  virtual ~Animal();

  std::string getType(void) const;
  virtual void makeSound(void) const;
};

void printLog(const std::string &message, const std::string &color);

#endif
