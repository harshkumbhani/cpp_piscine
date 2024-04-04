#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &src);
  RobotomyRequestForm & operator=(const RobotomyRequestForm &rhs);
  ~RobotomyRequestForm();

  void execute(const Bureaucrat &executor) const;
};

#endif
