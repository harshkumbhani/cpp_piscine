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

size_t Span::shortestSpan() {
  if (span.size() < 2)
    throw SpanNotFound();

  size_t result = std::numeric_limits<size_t>::max();
  std::sort(span.begin(), span.end());
  std::vector<int>::iterator it;
  for (it = span.begin(); it + 1 != span.end(); it++) {
    size_t diff = static_cast<size_t>(std::abs(*(it + 1) - *it));
    result = std::min(result, diff);
  }
  return result;
}

size_t Span::longestSpan() const {
  if (span.size() < 2)
    throw SpanNotFound();

  std::vector<int>::const_iterator min =
      std::min_element(span.begin(), span.end());
  std::vector<int>::const_iterator max =
      std::max_element(span.begin(), span.end());

  return std::abs(*max - *min);
}

