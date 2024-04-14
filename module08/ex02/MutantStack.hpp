#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:
  MutantStack() : std::stack<T, Container>() {}
  MutantStack(const MutantStack<T, Container> &src)
      : std::stack<T, Container>(src) {}

  MutantStack<T, Container> &operator=(const MutantStack<T, Container> &rhs) {
    if (this != &rhs)
      std::stack<T, Container>::operator=(rhs);
    return *this;
  }

  ~MutantStack() {}

  typedef typename Container::iterator iterator;
  typedef typename Container::reverse_iterator reverse_iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  reverse_iterator rbegin() { return this->c.rbegin(); }
  reverse_iterator rend() { return this->c.rend(); }
};

#endif
