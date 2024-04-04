#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) { (void)src; }

Intern &Intern::operator=(const Intern &rhs) {
  (void)rhs;
  return *this;
}

Intern::~Intern() {}

AForm *Intern::makeShrubberyForm(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyForm(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
  std::string forms[_nbForms] = {"ShrubberyCreationForm", "RobotomyRequestForm",
                                 "PresidentialPardonForm"};

  AForm *(Intern::*formCreationArray[_nbForms])(const std::string &target) = {
      &Intern::makeShrubberyForm, &Intern::makeRobotomyForm,
      &Intern::makePresidentialPardonForm};

  for (int i = 0; i < _nbForms; i++) {
    if (forms[i].compare(name) == 0) {
      std::cout << "Intern creats " << forms[i] << std::endl;
      return (this->*formCreationArray[i])(target);
    }
  }
  throw std::runtime_error("You wanted a coffee ?");
}
