#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

class OutOfBounds :public std::runtime_error {
public:
  OutOfBounds(const std::string &msg);
};

template <typename T> class Array {
public:
  Array();
  Array(unsigned int n);
  Array(const Array &src);
  Array &operator=(const Array &rhs);
  ~Array();

  T &operator[](unsigned int index);
  unsigned int size() const;

private:
  unsigned int _n;
  T *array;
};

OutOfBounds::OutOfBounds(const std::string &msg) : std::runtime_error(msg) {}

template <typename T> Array<T>::Array() : _n(0), array(NULL) {}

template <typename T> Array<T>::Array(unsigned int n) : _n(n), array(new T[n]) {
  for (unsigned int i = 0; i < n; i++)
    array[i] = 0;
}

template <typename T>
Array<T>::Array(const Array &src) : _n(src._n), array(new T[src._n]) {
  for (unsigned int i = 0; i < _n; i++)
    this->array[i] = src.array[i];
}

template <typename T> Array<T> &Array<T>::operator=(const Array &rhs) {
  if (this != &rhs) {
    delete[] this->array;
    this->array = NULL;
    _n = rhs._n;
    if (_n > 0)
      array = new T[_n];
    for (unsigned int i = 0; i < rhs._n; i++) {
      array[i] = rhs.array[i];
    }
  }
  return *this;
}

template <typename T> Array<T>::~Array() { delete[] array; }

template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index >= _n)
    throw OutOfBounds("Index out of Bounds");
  return array[index];
}

template <typename T> unsigned int Array<T>::size() const { return _n; }

#endif
