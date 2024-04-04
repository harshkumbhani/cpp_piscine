#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Utils.hpp"

int main() {
  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("Starting Form and Bureaucrat Interaction Tests\n",
                     YELLOW);
  std::cout << color("========================================\n", BLUE);

  Bureaucrat highGradeBureaucrat("Alice", 1); // Highest possible grade
  Bureaucrat lowGradeBureaucrat("Bob", 150);  // Lowest possible grade

    std::cout << color("\n---> Test 1: ShrubberyCreationForm\n", YELLOW);
    ShrubberyCreationForm shrubberyForm("HomeGarden");
    highGradeBureaucrat.signForm(shrubberyForm);
    highGradeBureaucrat.executeForm(shrubberyForm);

    std::cout << color("\n---> Test 2: RobotomyRequestForm\n", YELLOW);
    RobotomyRequestForm robotomyForm("Employee");
    highGradeBureaucrat.signForm(robotomyForm);
    highGradeBureaucrat.executeForm(robotomyForm); // Note: Outcome is random

    std::cout << color("\n---> Test 3: PresidentialPardonForm\n", YELLOW);
    PresidentialPardonForm pardonForm("Criminal");
    highGradeBureaucrat.executeForm(pardonForm);
    highGradeBureaucrat.signForm(pardonForm);
    // lowGradeBureaucrat.executeForm(pardonForm);

  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("Form and Bureaucrat Interaction Tests Completed\n",
                     YELLOW);
  std::cout << color("========================================\n", BLUE);
  std::cout << std::endl;
  return 0;
}
