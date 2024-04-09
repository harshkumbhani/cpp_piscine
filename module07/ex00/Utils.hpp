#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";

const std::string HEADER = "\033[95m"; // Light magenta for headers
const std::string INFO = "\033[94m";   // Blue for informational text
const std::string SUCCESS = "\033[32m"; // Green for success or after operation
const std::string WARNING = "\033[33m"; // Yellow for before operation

// Function to apply color
void printLog(const std::string& text, const std::string& color = RESET);

#endif
