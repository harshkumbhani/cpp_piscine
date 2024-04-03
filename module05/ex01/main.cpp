#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Utils.hpp"

int main() {
  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("Starting Form and Bureaucrat Interaction Tests\n",
                     YELLOW);
  std::cout << color("========================================\n", BLUE);

  try {
    std::cout << color("\n---> Test 1: Constructing a Form with valid grades\n",
                       YELLOW);
    Form f1("Sports Budget Form", 50, 25); // Grades within the valid range
    std::cout << color("    SUCCESS: ", GREEN) << f1 << std::endl;

    std::cout << color("\n---> Test 2: Bureaucrat signs a Form successfully\n",
                       YELLOW);
    Bureaucrat highGradeBureaucrat("Alice",
                                   20); // Grade higher than the form's required
    highGradeBureaucrat.signForm(f1);
    std::cout << color("    SUCCESS: Form signed by Bureaucrat\n", GREEN);

  } catch (std::exception const &e) {
    std::cout << color("    FAILURE: Exception caught: ", RED) << e.what()
              << std::endl;
  }

  try {
    std::cout << color(
        "\n---> Test 3: Bureaucrat fails to sign Form due to low grade\n",
        YELLOW);
    Bureaucrat lowGradeBureaucrat(
        "Bob", 55); // Grade lower than the form's required to sign
    Form f2("Exclusive Club Membership", 50, 25);
    lowGradeBureaucrat.signForm(f2);

  } catch (std::exception const &e) {
    std::cout << color("    NOTE: This catch block might not be necessary if "
                       "signForm handles its exceptions internally.",
                       RED)
              << std::endl;
  }

  try {
    std::cout << color(
        "\n---> Test 4: Constructing a Form with too high a grade\n", YELLOW);
    Form f3("Impossible Task", 0, 25); // Grade too high

  } catch (std::exception const &e) {
    std::cout << color("    FAILURE: Exception caught: ", RED) << e.what()
              << std::endl;
  }

  try {
    std::cout << color(
        "\n---> Test 5: Constructing a Form with too low a grade\n", YELLOW);
    Form f4("Easy Task", 151, 150); // Grade too low

  } catch (std::exception const &e) {
    std::cout << color("    FAILURE: Exception caught: ", RED) << e.what()
              << std::endl;
  }

  std::cout << color("\n========================================\n", BLUE);
  std::cout << color("Form and Bureaucrat Interaction Tests Completed\n",
                     YELLOW);
  std::cout << color("========================================\n", BLUE);

  return 0;
}
