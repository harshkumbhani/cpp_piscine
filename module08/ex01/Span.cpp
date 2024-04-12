#include "Span.hpp"

Span::Span() : _max_size(0) {}

Span::Span(const size_t &N) : _max_size(N), span() { span.reserve(N); }

Span::Span(const Span &src) : _max_size(src._max_size), span(src.span) {}

Span &Span::operator=(const Span &rhs) {
  if (this != &rhs) {
    _max_size = rhs._max_size;
    span = rhs.span;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(const int &num) {
  if (span.size() < _max_size)
    span.push_back(num);
  else
    throw NoMoreSpaceInSpan();
}

void Span::print() const {
  for (size_t i = 0; i < span.size(); i++)
    std::cout << "index #" << i + 1 << " :  " << span[i] << std::endl;
}
