#include "MutantStack.hpp"
#include <vector>

void print_test_name(const std::string &test_name) {
  std::cout << "\n-----------------------------------\n";
  std::cout << "[TEST] " << test_name << "\n";
  std::cout << "-----------------------------------\n";
}

template <typename T>
void testIteration(const std::vector<T> &elements, bool reverse = false) {
  MutantStack<T> mstack;

  std::string test_name = reverse ? "Reverse Iterator Test" : "Iterator Test";
  print_test_name(test_name);
  for (typename std::vector<T>::const_iterator it = elements.begin();
       it != elements.end(); it++)
    mstack.push(*it);

  std::cout << "Printing all stack elements" << (reverse ? " in REVERSE" : "")
            << "....\n";
  if (!reverse) {
    for (typename MutantStack<T>::iterator it = mstack.begin();
         it != mstack.end(); ++it) {
      std::cout << *it << std::endl;
    }
  } else {
    for (typename MutantStack<T>::reverse_iterator it = mstack.rbegin();
         it != mstack.rend(); ++it) {
      std::cout << *it << std::endl;
    }
  }
  std::cout << "\nMstack Top: " << mstack.top() << std::endl;
  std::cout << "Mstack size: " << mstack.size() << std::endl;

  std::cout << "\nPopping top element\n";
  mstack.pop();
  std::cout << "\nMstack Top: " << mstack.top() << std::endl;
  std::cout << "MSTACK Size: " << mstack.size() << std::endl;
}

void  test_copy_constructor() {
 MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(7);
  mstack.push(10);
  mstack.push(-42);
  mstack.push(35);

  print_test_name("Copy constructor test");
  MutantStack<int> copyStack(mstack);
  std::cout << "Printing all stack elements....\n";
    for (MutantStack<int>::iterator it = copyStack.begin();
         it != copyStack.end(); ++it) {
      std::cout << *it << std::endl;
    }
  std::cout << "\nMstack Top: " << copyStack.top() << std::endl;
  std::cout << "Mstack size: " << copyStack.size() << std::endl;

  std::cout << "\nPopping top element\n";
  copyStack.pop();
  std::cout << "\nMstack Top: " << copyStack.top() << std::endl;
  std::cout << "Mstack size: " << copyStack.size() << std::endl;
  
}

int main() {

  int numsVector[] = {5, 7, 10, -42, 35};
  std::vector<int> v(numsVector, numsVector + sizeof(numsVector) /
                                                        sizeof(numsVector[0]));

  testIteration(v);
  testIteration(v, true);
  test_copy_constructor();
  return 0;
}
