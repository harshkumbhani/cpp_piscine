#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(128){};

Bureaucrat::Bureaucrat(int grade) : _name("Bureaucrat_00"), _grade(grade) {
  if (grade < 1)
    throw std::runtime_error("Bureaucrat::GradeTooHighException");
  if (grade > 150)
    throw std::runtime_error("Bureaucrat::GradeTooLowException");
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {
  if (grade < 1)
    throw std::runtime_error("Bureaucrat::GradeTooHighException");
  if (grade > 150)
    throw std::runtime_error("Bureaucrat::GradeTooLowException");
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : _name(src._name), _grade(src._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (this != &rhs) {
    _grade = rhs._grade;
  }
  return *this;
}

std::string const Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::increaseGrade(int gradeToIncrease) {
  if (_grade - gradeToIncrease < 1)
    throw std::runtime_error("Bureaucrat::GradeTooHighException");

  _grade -= gradeToIncrease;
}

void Bureaucrat::decreaseGrade(int gradeToIncrease) {
  if (_grade + gradeToIncrease > 150)
    throw std::runtime_error("Bureaucrat::GradeTooLowException");

  _grade += gradeToIncrease;
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << this->_name << " signed " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << this->_name << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(const AForm &form) {
  try {
    form.execute(*this);
    std::cout << this->_name << " executed " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << this->_name << " couldn't execute " << form.getName()
              << "form  because " << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat) {
  output << bureaucrat.getName() << ", bureaucrat grade "
         << bureaucrat.getGrade() << ".";
  return output;
}
