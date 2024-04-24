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
  for (vit it = input.begin(); it != input.end(); it += 2) {
    if (it + 1 == input.end()) {
      std::vector<int> single;
      single.push_back(input[input.size() - 1]);
      pairs.push_back(single);
      break;
    }
    std::vector<int> couple;
    couple.push_back(std::max(*it, *(it + 1)));
    couple.push_back(std::min(*it, *(it + 1)));
    pairs.push_back(couple);
  }
  std::sort(pairs.begin(), pairs.end(), PmergeMe::comparePairs);
  for (uditer it = pairs.begin(); it != pairs.end(); it++) {
    if (it->size() == 1) {
      append.push_back((*it)[0]);
      break;
    }
    main.push_back((*it)[0]);
    append.push_back((*it)[1]);
  }
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
  for (dit it = dinput.begin(); it != dinput.end(); it += 2) {
    if (it + 1 == dinput.end()) {
      std::vector<int> single;
      single.push_back(dinput[dinput.size() - 1]);
      deque_pairs.push_back(single);
      break;
    }
    std::vector<int> couple;
    couple.push_back(std::max(*it, *(it + 1)));
    couple.push_back(std::min(*it, *(it + 1)));
    deque_pairs.push_back(couple);
  }
  std::sort(deque_pairs.begin(), deque_pairs.end(), PmergeMe::comparePairs);
  for (udditer it = deque_pairs.begin(); it != deque_pairs.end(); it++) {
    if (it->size() == 1) {
      deque_append.push_back((*it)[0]);
      break;
    }
    deque_main.push_back((*it)[0]);
    deque_append.push_back((*it)[1]);
  }
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
  for (dit it = deque_main.begin(); it != deque_main.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
  std::cout << "Time to process a range of " << argc - 1
            << " elements with std::vector : " << vectorTime << "ms"
            << std::endl;
  std::cout << "Time to process a range of " << argc - 1
            << " elements with std::deque : " << dequeTime << "ms" << std::endl;
}
