#include "DiamondTrap.hpp"

int main(void) {
std::cout << GREEN << BOLD << "=== Creating DiamondTrap objects ===" << RESET << std::endl;
    DiamondTrap original("Original");
    original.whoAmI();

    std::cout << MAGENTA << BOLD << "\n=== Copying DiamondTrap object ===" << RESET << std::endl;
    DiamondTrap copyConstructed(original); // Using copy constructor
    copyConstructed.whoAmI();

    std::cout << YELLOW << BOLD << "\n=== Creating another DiamondTrap for assignment ===" << RESET << std::endl;
    DiamondTrap toBeAssigned("ToBeAssigned");
    toBeAssigned.whoAmI();

    std::cout << CYAN << BOLD << "\n=== Assigning DiamondTrap object ===" << RESET << std::endl;
    toBeAssigned = original; // Using copy assignment operator
    toBeAssigned.whoAmI();

    std::cout << RED << BOLD << "\n=== Demonstrating actions ===" << RESET << std::endl;
    original.attack("the target");
    copyConstructed.attack("another target");
    toBeAssigned.attack("a third target");

    std::cout << BLUE << BOLD << "\n=== Destructing DiamondTrap objects ===" << RESET << std::endl;
    // Objects original, copyConstructed, and toBeAssigned are automatically destructed here
    return 0;
}
