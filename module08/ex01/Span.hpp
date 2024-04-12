#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
private:
  size_t _max_size;
  std::vector<int> span;

public:
  Span();
  Span(const size_t &N);
  Span(const Span &src);
  Span &operator=(const Span &rhs);
  ~Span();

  void addNumber(const int &num);
  void print() const;
  size_t shortestSpan() const;

  class SpanNotFound : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "No Span could be Found :(";
    }
  };
  class NoMoreSpaceInSpan : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Span cannot add more numbers :(";
    }
  };
};

#endif
