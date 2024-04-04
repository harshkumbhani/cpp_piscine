#include "AForm.hpp"

AForm::AForm()
    : _name("undefined"), isSigned(false), gradeToSign(42), gradeToExecute(42),
      _target("Default") {}

AForm::AForm(const std::string &name, const int signGrade, const int exGrade,
             const std::string &target)
    : _name(name), isSigned(false), gradeToSign(signGrade),
      gradeToExecute(exGrade), _target(target) {
  if (signGrade < 1 || exGrade < 1)
    throw std::runtime_error("AForm::GradeTooHighException");
  if (signGrade > 150 || exGrade > 150)
    throw std::runtime_error("AForm::GradeTooLowException");
}

AForm::AForm(const AForm &src)
    : _name(src._name), isSigned(src.isSigned), gradeToSign(src.gradeToSign),
      gradeToExecute(src.gradeToExecute), _target(src._target) {}

AForm &AForm::operator=(const AForm &rhs) {
  if (this != &rhs) {
    isSigned = rhs.isSigned;
    _target = rhs._target;
  }
  return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }

const std::string &AForm::getTarget() const { return _target; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getGradeToSign() const { return gradeToSign; }

int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (this->gradeToSign < bureaucrat.getGrade())
    throw std::runtime_error("Bureaucrat level too low to sign the Form");
  if (this->isSigned == false)
    this->isSigned = true;
}

void AForm::checkExecutionReq(const Bureaucrat &bureaucrat) const {
  if (this->isSigned == false)
    throw std::runtime_error("Form has not been signed");

  if (this->gradeToExecute < bureaucrat.getGrade())
    throw std::runtime_error("Bureaucrat level too low to execute the Form");
}

std::ostream &operator<<(std::ostream &output, const AForm &form) {
  output << "\nAForm Name: " << form.getName()
         << "\nTarget Name: " << form.getTarget()
         << ",\nIs AForm Signed: " << (form.getIsSigned() ? "YES" : "NO")
         << ",\nGrade to Sign form: " << form.getGradeToSign()
         << ",\nGrade to Execute AForm: " << form.getGradeToExecute();

  return output;
}
