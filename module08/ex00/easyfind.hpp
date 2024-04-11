#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

class ElementNotFound : public std::exception {
public:
  virtual const char *what() const throw() {
    return "Element not found in the container :(";
  }
};

template <typename T>
typename T::iterator easyfind(T &container, int numToSearch) {
  typename T::iterator it =
      std::find(container.begin(), container.end(), numToSearch);

  if (it == container.end())
    throw ElementNotFound();
  else
    return it;
}

#endif
