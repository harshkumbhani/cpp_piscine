#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#define _nbForms 3

class Intern {
private:
public:
  Intern();
  Intern(const Intern &src);
  Intern &operator=(const Intern &rhs);
  ~Intern();

  AForm *makeShrubberyForm(const std::string &target);
  AForm *makeRobotomyForm(const std::string &target);
  AForm *makePresidentialPardonForm(const std::string &target);
  AForm *makeForm(const std::string &name, const std::string &target);
};

#endif
