#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"  // Wrong AAnimal, Brain
#define BLUE "\033[1;34m"    // AAnimal
#define MAGENTA "\033[1;35m" // Cat
#define CYAN "\033[1;36m"    // Dog

class AAnimal {
protected:
  std::string _type;

public:
  AAnimal();
  AAnimal(std::string type);
  AAnimal(const AAnimal &src);
  AAnimal &operator=(const AAnimal &rhs);
  virtual ~AAnimal();

  std::string getType(void) const;
  virtual void makeSound(void) const = 0;
};

void printLog(const std::string &message, const std::string &color);

#endif
