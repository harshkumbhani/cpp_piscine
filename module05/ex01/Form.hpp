#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
private:
  const std::string _name;
  bool isSigned;
  const int gradeToSign;
  const int gradeToExecute;

public:
  Form();
  Form(const std::string &name, const int signGrade, const int exGrade);
  Form(const Form &src);
  Form &operator=(const Form &rhs);
  ~Form();

  // Getters
  const std::string &getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &output, Form const &form);

#endif
