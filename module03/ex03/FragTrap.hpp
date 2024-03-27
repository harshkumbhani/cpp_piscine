#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
  private:
public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap &src);
  FragTrap& operator=(const FragTrap &rhs);
  ~FragTrap();

  void highFiveGuys(void);
};

#endif
