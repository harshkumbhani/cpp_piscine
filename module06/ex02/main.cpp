#include "Base.hpp"
#include "Functions.hpp"

int main() {

  std::cout << "Identifying using pointers" << std::endl;
  Base *p = generate();
  identify(p);
  delete p;
  
  std::cout << "Identifying using References" << std::endl;
  Base *q = generate();
  identify(*q);
  delete q;

  return 0;
}
