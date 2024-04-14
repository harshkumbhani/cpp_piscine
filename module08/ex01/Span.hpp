#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <limits>
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

  template <typename Iterator> void floodVector(Iterator begin, Iterator end) {
    size_t distance = std::distance(span.begin(), span.end());
    if (distance + span.size() > _max_size)
      throw NoMoreSpaceInSpan();
    span.insert(span.end(), begin, end);
  }

  std::vector<int> getSpan() const;

  void addNumber(const int &num);
  void print() const;
  size_t shortestSpan();
  size_t longestSpan() const;

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
