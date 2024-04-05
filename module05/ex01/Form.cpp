#include "Form.hpp"

Form::Form()
    : _name("TaxForm"), isSigned(false), gradeToSign(42), gradeToExecute(42) {}

Form::Form(const std::string &name, const int signGrade, const int exGrade)
    : _name(name), isSigned(false), gradeToSign(signGrade),
      gradeToExecute(exGrade) {
  if (signGrade < 1 || exGrade < 1)
    throw GradeTooHighException(_name +  " Grade too high");
  if (signGrade > 150 || exGrade > 150)
    throw GradeTooLowException(_name +  " Grade too Low");
}

Form::~Form() {}

Form::Form(const Form &src)
    : _name(src._name), isSigned(src.isSigned), gradeToSign(src.gradeToSign),
      gradeToExecute(src.gradeToExecute) {}

Form &Form::operator=(const Form &rhs) {
  if (this != &rhs) {
    isSigned = rhs.isSigned;
  }
  return *this;
}

const std::string &Form::getName() const { return _name; }

bool Form::getIsSigned() const { return isSigned; }

int Form::getGradeToSign() const { return gradeToSign; }

int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (this->gradeToSign < bureaucrat.getGrade())
    throw GradeTooLowException("bureaucrat Grade too Low");
  if (this->isSigned == false)
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &output, const Form &form) {
  output << "\nForm Name: " << form.getName()
         << ",\nIs Form Signed: " << (form.getIsSigned() ? "YES" : "NO")
         << ",\nGrade to Sign form: " << form.getGradeToSign()
         << ",\nGrade to Execute Form: " << form.getGradeToExecute();

  return output;
}
