#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";

// Function to apply color
std::string color(const std::string &text, const std::string &color);

#endif
