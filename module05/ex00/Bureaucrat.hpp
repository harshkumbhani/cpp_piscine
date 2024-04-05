#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

class GradeTooHighException : public std::runtime_error {
public:
  GradeTooHighException(const std::string &msg);
};

class GradeTooLowException : public std::runtime_error {
public:
  GradeTooLowException(const std::string &msg);
};

class Bureaucrat {
private:
  std::string const _name;
  int _grade;

public:
  Bureaucrat();
  Bureaucrat(int grade);
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &src);
  Bureaucrat & operator=(const Bureaucrat &rhs);
  ~Bureaucrat();

  // Getters
  std::string const getName() const;
  int getGrade() const;

  void increaseGrade(int gradeToIncrease);
  void decreaseGrade(int gradeToDecrease);
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat);

#endif
