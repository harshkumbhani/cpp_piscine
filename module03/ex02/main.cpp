#include "FragTrap.hpp"

int main(void) {
    {
    FragTrap frag("Frog");
        frag.attack("Grasshopper");
        frag.beRepaired(15);
        frag.highFiveGuys();
    }

  return 0;
}
