#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Utils.hpp"

void everythingWorks() {

  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("      High Grade Bureaucrat \n", YELLOW);
  std::cout << color("========================================\n", BLUE);
  Bureaucrat highGradeBureaucrat("Alice", 1); // Highest possible grade

  std::cout << color("\n---> Test 1: ShrubberyCreationForm\n", YELLOW);
  ShrubberyCreationForm shrubberyForm("HomeGarden");
  std::cout << shrubberyForm << "\n\n";
  highGradeBureaucrat.signForm(shrubberyForm);
  highGradeBureaucrat.executeForm(shrubberyForm);

  std::cout << color("\n---> Test 2: RobotomyRequestForm\n", YELLOW);
  RobotomyRequestForm robotomyForm("Employee");
  std::cout << robotomyForm << "\n\n";
  highGradeBureaucrat.signForm(robotomyForm);
  highGradeBureaucrat.executeForm(robotomyForm); // Note: Outcome is random

  std::cout << color("\n---> Test 3: PresidentialPardonForm\n", YELLOW);
  PresidentialPardonForm pardonForm("Criminal");
  std::cout << pardonForm << "\n\n";
  highGradeBureaucrat.executeForm(pardonForm);
  highGradeBureaucrat.signForm(pardonForm);
}

void partiallyWorks() {
  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("Mid grade Bureaucrat who grades is later decreased\n",
                     YELLOW);
  std::cout << color("========================================\n", BLUE);
  Bureaucrat midGradeBureaucrat("Eve", 70);
  std::cout << midGradeBureaucrat << std::endl;
  std::cout << color("\n---> Partial Test 1: Frank doing a Okay Job"
                     "for RobotomyRequestForm\n",
                     YELLOW);
  RobotomyRequestForm robotomyFormMidGrade("Android");
  midGradeBureaucrat.signForm(robotomyFormMidGrade);
  midGradeBureaucrat.signForm(robotomyFormMidGrade);
  midGradeBureaucrat.executeForm(robotomyFormMidGrade);

  std::cout << color("\n---> Partial Test 2: Frank got his grade hammered down "
                     "for PresidentialPardonForm\n",
                     YELLOW);
  midGradeBureaucrat.decreaseGrade(75);
  std::cout << midGradeBureaucrat << std::endl;
  PresidentialPardonForm pardonFormMidGrade("Rebel");
  midGradeBureaucrat.signForm(pardonFormMidGrade);
  midGradeBureaucrat.executeForm(pardonFormMidGrade);

  std::cout << color(
      "\n---> Partial Test 3: Frank was nice so he rank is now increased "
      "ShrubberyCreationForm\n",
      YELLOW);
  midGradeBureaucrat.increaseGrade(5);
  std::cout << midGradeBureaucrat << std::endl;
  ShrubberyCreationForm shrubberyFormNoWrite("ReadOnlyGarden");
  midGradeBureaucrat.signForm(shrubberyFormNoWrite);
  midGradeBureaucrat.executeForm(shrubberyFormNoWrite);
}

void nothingWorks() {
  std::cout << color("\n========================================\n", YELLOW);
  std::cout << color("A Tale of a Drunken Bureaucrat Named Bob\n", BLUE);
  std::cout << color("========================================\n", YELLOW);

  Bureaucrat drunkenBob("Bob", 100); // Bob starts with a moderate grade
  std::cout << drunkenBob << std::endl;

  std::cout << color(
      "\n---> Scene 1: Bob's Attempt at a Coup with a RobotomyRequestForm\n",
      GREEN);
  RobotomyRequestForm coupForm("TheCoffeeMachine");
  std::cout << color(
      "In a bout of overconfidence, Bob attempts to execute an operation on \n"
      "TheCoffeeMachine without proper authorization.\n",
      YELLOW);
  drunkenBob.executeForm(coupForm);

  // Continuing with the story
  drunkenBob.decreaseGrade(25);
  std::cout << color(
      "After the fiasco, the council demotes Bob for his reckless behavior. \n",
      YELLOW);
  std::cout << drunkenBob << std::endl;
  std::cout << color(
      "\n---> Scene 2: Bob's Misguided Efforts with a PresidentialPardonForm\n",
      GREEN);
  PresidentialPardonForm pardonForm("Himself");
  std::cout << color("Bob, still not deterred, tries to pardon himself for \n"
                     "past transgressions without filing the paperwork.\n",
                     YELLOW);
  drunkenBob.executeForm(
      pardonForm); // Assuming this prints an error instead of throwing

  std::cout << color(
      "\n---> Scene 3: Bob's Redemption Arc with a ShrubberyCreationForm\n",
      GREEN);
  ShrubberyCreationForm gardenForm("TheOfficeBackyard");
  std::cout << color("Seeking redemption, Bob aims to beautify the office. "
                     "Yet, in his usual style, he bypasses all protocols.\n",
                     YELLOW);
  drunkenBob.executeForm(
      gardenForm); // Assuming this prints an error instead of throwing

  std::cout << color(
      "\nIn the end, Bob's heart was in the right place, but his methods were "
      "\n"
      "as erratic as his sobriety. The office remains unchanged, and Bob is \n"
      "left to ponder his actions.\n",
      RED);
  std::cout << color("\n========================================\n", YELLOW);
  std::cout << color("The End of Bob's Misadventures\n", BLUE);
  std::cout << color("========================================\n", YELLOW);
  std::cout << std::endl;
}

int main() {
  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("Starting Form and Bureaucrat Interaction Tests\n",
                     YELLOW);
  std::cout << color("========================================\n", BLUE);

  everythingWorks();
  partiallyWorks();
  nothingWorks();

  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("Form and Bureaucrat Interaction Tests Completed\n",
                     YELLOW);
  std::cout << color("========================================\n", BLUE);
  std::cout << std::endl;
  return 0;
}
