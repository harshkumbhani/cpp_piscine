#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

class Bureaucrat {
private:
  std::string const _name;
  int _grade;

public:
  Bureaucrat();
  Bureaucrat(int grade);
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();

  // Getters
  std::string const getName() const;
  int getGrade() const;

  void increaseGrade(int gradeToIncrease);
  void decreaseGrade(int gradeToDecrease);
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat);

#endif
