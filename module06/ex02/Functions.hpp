#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp"

class badCast : public std::runtime_error {
public:
  badCast(const std::string &msg);
};

Base *generate(void);

void identify(Base *p);

void identify(Base &p);

#endif
