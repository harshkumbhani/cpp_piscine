#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
  static const std::string treeDesign;
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &src);
  ShrubberyCreationForm & operator=(const ShrubberyCreationForm &rhs);
  ~ShrubberyCreationForm();

  void execute(const Bureaucrat &executor) const;
};

#endif
