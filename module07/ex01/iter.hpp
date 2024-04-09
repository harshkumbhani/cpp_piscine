#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Function>
void iter(T *array, size_t size, Function function) {
  for (size_t i = 0; i < size; i++) {
    function(array[i]);
  }
  std::cout << std::endl;
}

template <typename T> void print(T &element) {
  std::cout << element << std::endl;
}

template <typename T> void incrementValue(T &element) { ++element; }

#endif
