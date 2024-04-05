#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

class Form;

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
  const std::string _name;
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

  void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat);

#endif
