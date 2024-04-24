#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";

class PmergeMe {
private:
  std::deque<std::vector<int> > deque_pairs;
  std::deque<int> deque_main;
  std::deque<int> deque_append;
  std::deque<int> dinput;
  std::vector<std::vector<int> > pairs;
  std::vector<int> main;
  std::vector<int> append;
  std::vector<int> input;

public:
  // typedefs
  typedef std::vector<std::vector<int> >::iterator uditer;
  typedef std::vector<int>::iterator vit;

  typedef std::deque<std::vector<int> >::iterator udditer;
  typedef std::deque<int>::iterator dit;
  // Constructors and Destructors
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  ~PmergeMe();

  // Operator overlods
  PmergeMe &operator=(const PmergeMe &rhs);

  void sortMe(int argc, char **argv);
  void sortUsingVector(int argc, char **argv);
  void sortUsingDeque(int argc, char **argv);
  static bool comparePairs(const std::vector<int> &a,
                           const std::vector<int> &b);
  double measureComputationTime(void (PmergeMe::*sortFunction)(int, char **),
                                int argc, char **argv);

  class InvalidInput : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Invalid Input, contains numbers < 0 or unknown characters";
    }
  };

  template <typename Container>
  bool isSorted(const Container &container) {
    for (size_t i = 0; i < container.size() - 1; i++) {
      if (container[i] > container[i + 1])
        return false;
    }
    return true;
  }


  template <typename Container>
  void printPairs(const Container &container) const {
    for (size_t i = 0; i < container.size(); ++i) {
      for (size_t j = 0; j < container[i].size(); ++j) {
        std::cout << container[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  template <typename Container>
  void parseInput(int ac, char *av[], Container &box) {
    int val = 0;
    for (int i = 1; i < ac; i++) {
      std::string arg(av[i]);
      if (arg.empty() == true ||
        arg.find_first_not_of(" \t\r") == std::string::npos)
        throw PmergeMe::InvalidInput();
      std::stringstream ss(arg);

      ss >> val;
      if (val < 0 || ss.eof() != true)
        throw PmergeMe::InvalidInput();
      box.push_back(val);
      ss.clear();
    }
  }

  template <typename Container>
  void doBinaryInsertion(Container &main, Container &append, Container &jsn) {
    typedef typename Container::iterator bit;
    main.insert(main.begin(), append[0]);
    if (append.size() > 1 && jsn.size() > 1) {
      bit it = std::lower_bound(main.begin(), main.end(), append[1]);
      main.insert(it, append[1]);
    }
    for (size_t i = 2; i < jsn.size(); i++) {
      size_t j = jsn[i - 1];
      size_t k = jsn[i];
      if (k > append.size() - 1)
        k = append.size() - 1;
      while (k > j) {
        bit it = std::lower_bound(main.begin(), main.end(), append[k]);
        main.insert(it, append[k]);
        --k;
      }
    }
  }

  template <typename Container>
  Container generateJacobsthalNumbers(const int size) {
    Container jsn;

    if (size > 0)
      jsn.push_back(0);
    if (size > 1)
      jsn.push_back(1);
    int i = 2;
    while (true) {
      int level = jsn[i - 1] + 2 * jsn[i - 2];
      jsn.push_back(level);
      if (size < jsn[i])
        break;
      i++;
    }
    return jsn;
  }
};

#endif
