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

void PmergeMe::printPairs() const {
  for (size_t i = 0; i < pairs.size(); ++i) {
    for (size_t j = 0; j < pairs[i].size(); ++j) {
      std::cout << pairs[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

bool PmergeMe::comparePairs(const std::vector<int> &a,
                            const std::vector<int> &b) {
  if (a.size() > 1 && b.size() > 1) {
    return a[0] < b[0];
  }
  return false;
}

void PmergeMe::doBinaryInsertion(std::vector<int> &main,
                                 std::vector<int> &append) {
  vit main_it;
  vit append_it;

  main.insert(main.begin(), append[0]);
  for (append_it = ++append.begin(); append_it != append.end(); append_it++) {
    int startPos = 0;
    int endPos = main.size() - 1;
    int midPoint = 0;
    while (startPos <= endPos) {
      midPoint = (startPos + endPos) / 2;
      if (*append_it < main[midPoint])
        endPos = midPoint - 1;
      else
        startPos = midPoint + 1;
    }
    main.insert(main.begin() + startPos, *append_it);
  }
}

void PmergeMe::sortUsingVector(int argc, char *argv[]) {
  std::vector<int> input;
  parseInput<std::vector<int> >(argc, argv, input);
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
  doBinaryInsertion(main, append);
  std::cout << "Main chain: " << std::endl;
  for (vit it = main.begin(); it != main.end(); it++)
    std::cout << *it << std::endl; // for debugging purpose
}

void PmergeMe::sortMe(int argc, char **argv) { sortUsingVector(argc, argv); }
