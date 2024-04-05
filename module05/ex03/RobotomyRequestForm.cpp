#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45, "default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  checkExecutionReq(executor);

  std::cout << "Zzzzzrrrrrrggggggghhhhh, zrrrrggghhhh, zrrrrggghhhhhhh!"
            << std::endl;
  srand(time(NULL));
  if (rand() % 2 == 0) {
    std::cout << "Robotomy on " << getTarget() << " successfull." << std::endl;
  } else {
    std::cout << "Robotomy on " << getTarget() << " failed." << std::endl;
  }
}
