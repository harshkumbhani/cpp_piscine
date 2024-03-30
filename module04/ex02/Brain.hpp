#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "AAnimal.hpp"

class Brain {
private:
  std::string _ideas[100];

public:
  Brain();
  Brain(const Brain &src);
  Brain &operator=(const Brain &rhs);
  ~Brain();

  std::string getIdea(int index) const;
  void setIdea(int index, const std::string &idea);
  void printIdeas(void) const;
};

#endif
