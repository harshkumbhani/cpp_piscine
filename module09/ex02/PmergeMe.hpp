#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <algorithm>
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
  std::vector<std::vector<int> > pairs;
  std::vector<int> main;
  std::vector<int> append;

public:
  // typedefs
  typedef std::vector<std::vector<int> >::iterator uditer;
  typedef std::vector<int>::iterator vit;

  // Constructors and Destructors
  PmergeMe();
  PmergeMe(const PmergeMe &src);
  ~PmergeMe();

  // Operator overlods
  PmergeMe &operator=(const PmergeMe &rhs);

  void sortMe(int argc, char **argv);
  void sortUsingVector(int argc, char **argv);
  void printPairs() const;
  void doBinaryInsertion(std::vector<int> &main, std::vector<int> &append,
                         std::vector<int> &jsn);
  std::vector<int> generateJacobsthalNumbers(const int size);
  static bool comparePairs(const std::vector<int> &a,
                           const std::vector<int> &b);

  class InvalidInput : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Invalid Input, contains numbers < 0 or unknown characters";
    }
  };

  template <typename Container>
  void parseInput(int ac, char *av[], Container &box) {
    int val = 0;
    for (int i = 1; i < ac; i++) {
      std::string arg(av[i]);
      std::stringstream ss(arg);

      ss >> val;
      if (val < 0 || ss.eof() != true)
        throw PmergeMe::InvalidInput();
      box.push_back(val);
      ss.clear();
    }
  }
};

#endif
