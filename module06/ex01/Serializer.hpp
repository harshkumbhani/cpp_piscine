#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include <cstdlib>

struct Data; 

class Serializer {
private:
  Serializer();
  Serializer(const Serializer &src);
  Serializer & operator=(const Serializer &rhs);
  ~Serializer();

public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

#endif
