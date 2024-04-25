#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : pairs(), main(), append() {}

PmergeMe::PmergeMe(const PmergeMe &src)
    : pairs(src.pairs), main(src.main), append(src.append) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  PmergeMe temp(rhs);
  std::swap(this->pairs, temp.pairs);
  std::swap(this->main, temp.main);
  std::swap(this->main, temp.append);
  return *this;
}

bool PmergeMe::comparePairs(const std::vector<int> &a,
                            const std::vector<int> &b) {
  if (a.size() > 1 && b.size() > 1) {
    return a[0] < b[0];
  }
  return false;
}

double PmergeMe::measureComputationTime(void (PmergeMe::*sortFunction)(int,
                                                                       char **),
                                        int argc, char **argv) {
  clock_t startTime = clock();
  (this->*sortFunction)(argc, argv);
  clock_t endTime = clock();

  return (endTime - startTime) * 1000.0 / CLOCKS_PER_SEC;
}

void PmergeMe::sortUsingVector(int argc, char *argv[]) {
  std::vector<int> jsn;

  parseInput<std::vector<int> >(argc, argv, input);
  if (PmergeMe::isSorted(input) == true) {
    main = input;
    return;
  }
  if (input.size() == 1) {
    main = input;
    return;
  }
  if (input.size() == 2) {
    main = input;
    if (main[0] > main[1])
      std::swap(main[0], main[1]);
    return;
  }
  for (size_t i = 0; i + 1 < input.size(); i += 2) {
    std::vector<int> couple;
    couple.push_back(std::max(input[i], input[i + 1]));
    couple.push_back(std::min(input[i], input[i + 1]));
    pairs.push_back(couple);
  }
  PmergeMe::mergeInsertionSort<std::vector<std::vector<int> > >(pairs);
  for (uditer it = pairs.begin(); it != pairs.end(); it++) {
    main.push_back((*it)[0]);
    append.push_back((*it)[1]);
  }
  if (input.size() % 2 != 0)
    append.push_back(input[input.size() - 1]);
  jsn = PmergeMe::generateJacobsthalNumbers<std::vector<int> >(append.size());
  PmergeMe::doBinaryInsertion<std::vector<int> >(main, append, jsn);
}

void PmergeMe::sortUsingDeque(int argc, char *argv[]) {
  std::deque<int> jsn;

  parseInput<std::deque<int> >(argc, argv, dinput);
  if (PmergeMe::isSorted<std::deque<int> >(dinput) == true) {
    deque_main = dinput;
    return;
  }
  if (dinput.size() == 1) {
    deque_main = dinput;
    return;
  }
  if (dinput.size() == 2) {
    deque_main = dinput;
    if (deque_main[0] > deque_main[1])
      std::swap(deque_main[0], deque_main[1]);
    return;
  }
  for (size_t i = 0; i + 1 < dinput.size(); i += 2) {
    std::vector<int> couple;
    couple.push_back(std::max(dinput[i], dinput[i + 1]));
    couple.push_back(std::min(dinput[i], dinput[i + 1]));
    deque_pairs.push_back(couple);
  }
  PmergeMe::mergeInsertionSort<std::deque<std::vector<int> > >(deque_pairs);
  for (udditer it = deque_pairs.begin(); it != deque_pairs.end(); it++) {
    deque_main.push_back((*it)[0]);
    deque_append.push_back((*it)[1]);
  }
  if (dinput.size() % 2 != 0)
    deque_append.push_back(dinput[dinput.size() - 1]);
  jsn =
      PmergeMe::generateJacobsthalNumbers<std::deque<int> >(deque_append.size());
  PmergeMe::doBinaryInsertion<std::deque<int> >(deque_main, deque_append, jsn);
}

void PmergeMe::sortMe(int argc, char **argv) {
  double vectorTime;
  double dequeTime;

  dequeTime = measureComputationTime(&PmergeMe::sortUsingDeque, argc, argv);
  vectorTime = measureComputationTime(&PmergeMe::sortUsingVector, argc, argv);
  std::cout << "Before: ";
  for (vit it = input.begin(); it != input.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
  std::cout << "After: ";
  std::cout << "\nVector: ";
  for (vit it = main.begin(); it != main.end(); it++)
    std::cout << *it << " ";
  std::cout << "\ndeque: ";
  for (dit it = deque_main.begin(); it != deque_main.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
  std::cout << "Time to process a range of " << main.size()
            << " elements with std::vector : " << vectorTime << "ms"
            << std::endl;
  std::cout << "Time to process a range of " << deque_main.size()
            << " elements with std::deque : " << dequeTime << "ms" << std::endl;
}
