#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Utils.hpp"

int main() {

  Bureaucrat farshad(3);
  ShrubberyCreationForm tree("House");

  farshad.signForm(tree);
  farshad.executeForm(tree);

  RobotomyRequestForm robot("Bob");

  farshad.signForm(robot);
  farshad.executeForm(robot);

  PresidentialPardonForm grant("Oreste");

  farshad.signForm(grant);
  farshad.executeForm(grant);
  return 0;
}
