#include "iter.hpp"

int main() {

  int arr[] = {1, 2, 3, 4, 5};
  std::string fruits[5] = {"Apple", "Banana", "Calamansi", "Date", "EggPlant"};

  iter(arr, 5, print<int>);

  iter(arr, 5, incrementValue<int>);
  iter(arr, 5, print<int>);
  iter(fruits, 5, print<std::string>);
  return 0;
}


