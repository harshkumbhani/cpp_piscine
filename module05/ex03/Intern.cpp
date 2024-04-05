#include "Intern.hpp"

Intern::FormNotFound::FormNotFound(const std::string &msg)
    : std::runtime_error(msg) {}

const std::string Intern::forms[_nbForms] = {
    "Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

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

  AForm *(Intern::*formCreationArray[_nbForms])(const std::string &target) = {
      &Intern::makeShrubberyForm, &Intern::makeRobotomyForm,
      &Intern::makePresidentialPardonForm};

  for (int i = 0; i < _nbForms; i++) {
    if (forms[i].compare(name) == 0) {
      std::cout << "Intern creates " << forms[i] << std::endl;
      return (this->*formCreationArray[i])(target);
    }
  }
  throw FormNotFound("Form not found. It's probably out chasing unicorns!");
}
