#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>
#include <sstream>

class AForm {
private:
  const std::string _name;
  bool isSigned;
  const int gradeToSign;
  const int gradeToExecute;
  std::string _target;

public:
  AForm();
  AForm(const std::string &name, const int signGrade, const int exGrade,
        const std::string &target);
  AForm(const AForm &src);
  AForm &operator=(const AForm &rhs);
  virtual ~AForm();

  // Getters
  const std::string &getName() const;
  const std::string &getTarget() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);
  void checkExecutionReq(const Bureaucrat &bureaucrat) const;
  virtual void execute(const Bureaucrat &executor) const = 0;
  ;
};

std::ostream &operator<<(std::ostream &output, AForm const &form);

#endif
