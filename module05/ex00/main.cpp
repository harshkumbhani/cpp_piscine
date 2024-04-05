#include "Bureaucrat.hpp"
#include "Utils.hpp"

void workingBureaucrat() {

  std::cout << color(
      "\n---> Test 1: Constructing a Bureaucrat with a valid grade\n", YELLOW);
  try {
    Bureaucrat b1("John Doe", 75);
    std::cout << color("    SUCCESS: ", GREEN) << b1 << std::endl;

    std::cout << color(
        "\n    ---> Test 1.1: Increasing grade within valid range\n", YELLOW);
    b1.increaseGrade(10);
    std::cout << color("        SUCCESS: After increasing grade: ", GREEN) << b1
              << std::endl;

    std::cout << color(
        "\n    ---> Test 1.2: Decreasing grade within valid range\n", YELLOW);
    b1.decreaseGrade(20);
    std::cout << color("        SUCCESS: After decreasing grade: ", GREEN) << b1
              << std::endl;

  } catch (std::exception const &e) {
    std::cout << color("        FAILURE: Exception caught: ", RED) << e.what()
              << std::endl;
  }
}

void tooHighGradeBureaucrat() {

  std::cout << color(
      "\n---> Test 2: Constructing a Bureaucrat with too high a grade\n",
      YELLOW);
  try {
    Bureaucrat b2("Max Power", 0);
  } catch (std::exception const &e) {
    std::cout << color("    FAILURE: Exception caught: ", RED) << e.what()
              << std::endl;
  }
}

void tooLowGradeBureaucrat() {

  std::cout << color(
      "\n---> Test 3: Constructing a Bureaucrat with too low a grade\n",
      YELLOW);
  try {
    Bureaucrat b3("Min Effort", 151);
  } catch (std::exception const &e) {
    std::cout << color("    FAILURE: Exception caught: ", RED) << e.what()
              << std::endl;
  }
}

void changingGradeToInvalid() {

  std::cout << color("\n---> Test 4: Increasing grade beyond the upper limit\n",
                     YELLOW);
  try {
    Bureaucrat b4("Risky Business", 10);
    std::cout << b4 << std::endl;
    b4.increaseGrade(15); // This should throw
  } catch (std::exception const &e) {
    std::cout << color("    FAILURE: Exception caught: ", RED) << e.what()
              << std::endl;
  }

  std::cout << color("\n---> Test 5: Decreasing grade beyond the lower limit\n",
                     YELLOW);
  try {
    Bureaucrat b5("Safe Bet", 145);
    std::cout << b5 << std::endl;
    b5.decreaseGrade(10); // This should throw
  } catch (std::exception const &e) {
    std::cout << color("    FAILURE: Exception caught: ", RED) << e.what()
              << std::endl;
  }
}

int main() {
  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("Starting Bureaucrat Class Tests\n", YELLOW);
  std::cout << color("========================================\n", BLUE);

  workingBureaucrat();
  tooHighGradeBureaucrat();
  tooLowGradeBureaucrat();
  changingGradeToInvalid();

  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("Bureaucrat Class Tests Completed\n", YELLOW);
  std::cout << color("========================================\n", BLUE);

  return 0;
}
