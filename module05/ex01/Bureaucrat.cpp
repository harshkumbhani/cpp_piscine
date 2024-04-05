#include "Bureaucrat.hpp"
#include "Form.hpp"

GradeTooHighException::GradeTooHighException(const std::string &msg)
    : std::runtime_error(msg) {}

GradeTooLowException::GradeTooLowException(const std::string &msg)
    : std::runtime_error(msg) {}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(128){};

Bureaucrat::Bureaucrat(int grade) : _name("Bureaucrat_00"), _grade(grade) {
  if (grade < 1)
    throw GradeTooHighException(_name +  " Grade too high");
  if (grade > 150)
    throw GradeTooLowException(_name +  " Grade too Low");
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {
  if (grade < 1)
    throw GradeTooHighException(_name +  " Grade too high");
  if (grade > 150)
    throw GradeTooLowException(_name +  " Grade too Low");
}

Bureaucrat::~Bureaucrat() {}

std::string const Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::increaseGrade(int gradeToIncrease) {
  if (_grade - gradeToIncrease < 1)
    throw GradeTooHighException(_name +  " Grade too high");

  _grade -= gradeToIncrease;
}

void Bureaucrat::decreaseGrade(int gradeToIncrease) {
  if (_grade + gradeToIncrease > 150)
    throw GradeTooLowException(_name +  " Grade too Low");

  _grade += gradeToIncrease;
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << this->_name << " signed " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << this->_name << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat) {
  output << bureaucrat.getName() << ", bureaucrat grade "
         << bureaucrat.getGrade() << ".";
  return output;
}
