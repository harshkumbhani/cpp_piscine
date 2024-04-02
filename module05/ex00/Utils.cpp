#include "Utils.hpp"


// Function to apply color
std::string color(const std::string& text, const std::string& color) {
    return color + text + RESET;
}
