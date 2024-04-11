#include "easyfind.hpp"
#include <list>
#include <vector>

void print_test_name(const std::string &test_name) {
  std::cout << "[TEST] " << test_name << "\n";
}

template <typename Container>
void test_find_in_container(const std::string &description, int numToSearch,
                            Container &container) {
  print_test_name(description);
  try {
    typename Container::iterator it = easyfind(container, numToSearch);
    int position = std::distance(container.begin(), it);
    std::cout << "Number " << numToSearch << " found at position "
              << position + 1 << " in the container: { ";
    for (typename Container::iterator iter = container.begin();
         iter != container.end(); ++iter) {
      std::cout << *iter << " ";
    }
    std::cout << "}\n\n";
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n\n";
  }
}

int main() {
  int numsVector[] = {8, 4, 5, 9};
  std::vector<int> vector1(numsVector, numsVector + sizeof(numsVector) /
                                                        sizeof(numsVector[0]));
  std::vector<int> vector2(numsVector, numsVector + sizeof(numsVector) /
                                                        sizeof(numsVector[0]));
  vector2.push_back(42);

  int numsList[] = {8, 4, 5, 9};
  std::list<int> list1(numsList,
                       numsList + sizeof(numsList) / sizeof(numsList[0]));
  std::list<int> list2(numsList,
                       numsList + sizeof(numsList) / sizeof(numsList[0]));
  list2.push_back(42);

  test_find_in_container("Find number in vector.", 5, vector1);
  test_find_in_container("Number not found in vector.", 42, vector1);
  test_find_in_container("Find number in vector.", 42, vector2);
  test_find_in_container("Number not found in vector.", 100, vector2);

  test_find_in_container("Find number in list.", 5, list1);
  test_find_in_container("Number not found in list.", 42, list1);
  test_find_in_container("Find number in list.", 42, list2);
  test_find_in_container("Number not found in list.", 100, list2);

  return 0;
}
