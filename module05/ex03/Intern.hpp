#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define _nbForms 3

class Intern {
private:
  static const std::string forms[_nbForms];
  AForm *makeShrubberyForm(const std::string &target);
  AForm *makeRobotomyForm(const std::string &target);
  AForm *makePresidentialPardonForm(const std::string &target);

public:
  Intern();
  Intern(const Intern &src);
  Intern &operator=(const Intern &rhs);
  ~Intern();

  class FormNotFound : public std::runtime_error {
  public:
    FormNotFound(const std::string &msg);
  };

  AForm *makeForm(const std::string &name, const std::string &target);
};

#endif
