#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Utils.hpp"

void test_shrubbery_form() {

  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("      SHRUBBERY CREATION FORM TRAINING \n", YELLOW);
  std::cout << color("========================================\n", BLUE);
  Bureaucrat Espresso_Patronum("Espresso_Patronum", 3);
  Intern Pixel_Waffle;
  AForm *shrubbey = Pixel_Waffle.makeForm("Shrubbery Creation", "MARS");

  Espresso_Patronum.signForm(*shrubbey);
  Espresso_Patronum.executeForm(*shrubbey);
  delete shrubbey;
}

void test_robotomy_form() {
  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("      ROBOTOMY REQUEST FORM TRAINING\n", YELLOW);
  std::cout << color("========================================\n", BLUE);
  Bureaucrat Cypher_Doc("Cypher_Doc", 3);
  Intern Palette_Turner;
  AForm *robotomy = Palette_Turner.makeForm("Robotomy Request", "42 GPT");

  Cypher_Doc.signForm(*robotomy);
  Cypher_Doc.executeForm(*robotomy);
  delete robotomy;
}

void test_presidential_pardon_form() {
  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("      PRESIDENTAIL PARDON FORM TRAINING\n", YELLOW);
  std::cout << color("========================================\n", BLUE);
  Bureaucrat justus("Justus Fairway", 3);
  Intern Page_Turner;
  AForm *pardon = Page_Turner.makeForm("Presidential Pardon", "Mercu Fuller");

  justus.signForm(*pardon);
  justus.executeForm(*pardon);
  delete pardon;
}

void test_non_existing_form() {
  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("      NON EXISTING FORM TRAINING\n", YELLOW);
  std::cout << color("========================================\n", BLUE);
  Bureaucrat Cypher_Doc("Cypher_Doc", 3);
  Intern Palette_Turner;

  try {
    AForm *pardon = Palette_Turner.makeForm("Hi i don't Exist", "42 GPT");
    Cypher_Doc.signForm(*pardon);
    Cypher_Doc.executeForm(*pardon);
    delete pardon;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

int main() {
  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("      Intern training starts\n", YELLOW);
  std::cout << color("========================================\n", BLUE);

  test_shrubbery_form();
  test_robotomy_form();
  test_presidential_pardon_form();
  test_non_existing_form();

  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("  Intern training Ends\n", YELLOW);
  std::cout << color("========================================\n", BLUE);
  std::cout << std::endl;
  return 0;
}
