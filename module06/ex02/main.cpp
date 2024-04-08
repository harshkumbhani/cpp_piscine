#include "Base.hpp"
#include "Functions.hpp"

int main () {

  // Base *test = generate();
  // identify(NULL);

  Base *p = generate();

  identify(*p);
  return 0;
}
