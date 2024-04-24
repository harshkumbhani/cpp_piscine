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

std::vector<int> PmergeMe::generateJacobsthalNumbers(const int size) {
  std::vector<int> jsn;

  if (size > 0)
    jsn.push_back(0);
  if (size > 1)
    jsn.push_back(1);
  for (int i = 2; i < size; i++) {
    int level = jsn[i - 1] + 2 * jsn[i - 2];
    jsn.push_back(level);
    if (size < jsn[i])
      break;
  }
  return jsn;
}


void PmergeMe::doBinaryInsertion(std::vector<int> &main,
                                 std::vector<int> &append,
                                 std::vector<int> &jsn) {
  main.insert(main.begin(), append[0]);
  if (append.size() > 1 && jsn.size() > 1) {
    vit it = std::lower_bound(main.begin(), main.end(), append[1]);
    main.insert(it, append[1]);
  }
  for (size_t i = 2; i < jsn.size(); i++) {
    size_t j = jsn[i - 1];
    size_t k = jsn[i];
    if (k > append.size() - 1)
      k = append.size() - 1;
    while (k > j) {
      vit it = std::lower_bound(main.begin(), main.end(), append[k]);
      main.insert(it, append[k]);
      --k;
    }
  }
}

void PmergeMe::sortUsingVector(int argc, char *argv[]) {
  std::vector<int> input;
  std::vector<int> jsn;

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
  jsn = PmergeMe::generateJacobsthalNumbers(append.size());
  doBinaryInsertion(main, append, jsn);
  std::cout << "Unsorted:           Sorted:" << std::endl;
  for (size_t i = 0; i < main.size(); i++)
    std::cout << input[i] << "                   " << main[i] << std::endl;
}

void PmergeMe::sortMe(int argc, char **argv) { sortUsingVector(argc, argv); }
