#include "Point.hpp"

void printFancyMessage() {
    std::cout << CYAN << "================= Barycentric Coordinates =================\n" << RESET;
    std::cout << GREEN << "A point p is inside the triangle defined by a, b, c if and only if:\n" << RESET;
    std::cout << YELLOW << "0 < α < 1\n0 < β < 1\n0 < γ < 1\n" << RESET;
    std::cout << RED << "1. " << "If one of the barycentric coordinates is 0\n and the other two are between 0 and 1,\n the corresponding point p is on one of the edges of the triangle.\n" << RESET;
    std::cout << RED << "2. " << "If two of the barycentric coordinates are zero and\n the third is 1, the point p is at one of the vertices of the triangle.\n" << RESET;
    std::cout << CYAN << "===========================================================\n" << RESET;
}

int main() {
  const Point a(0.0f, 0.0f);
  const Point b(10.0f, 0.0f);
  const Point c(0.0f, 10.0f);
  //
  // const Point insidePoint(0.0f, 8.0f);
  // std::cout << std::boolalpha;
  // if (bsp(a, b, c, insidePoint) == true)
  //   std::cout << "true" << std::endl;
  // else
  //   std::cout << "false" << std::endl;
  // return (0);
  std::cout << "+---------------------------------------------+\n";
  std::cout << "|      🌟 Triangle Point Locator 🌟          |\n";
  std::cout << "|   Check if a point is inside a triangle    |\n";
  std::cout << "+---------------------------------------------+\n";

  printFancyMessage();
  while (true) {
    float px, py;
    char decision;

    std::cout << "\nDo you want to enter a point? (y/n): ";
    std::cin >> decision;
    if (decision != 'y' && decision != 'Y') {
      break; // Exit the loop if user chooses not to continue
    }

    std::cout << "Enter the x-coordinate of point P: ";
    while (!(std::cin >> px)) {
      std::cout << "Invalid input. Please enter a valid number: ";
    }

    std::cout << "Enter the y-coordinate of point P: ";
    while (!(std::cin >> py)) {
      std::cout << "Invalid input. Please enter a valid number: ";
    }

    Point p(px, py); // User-defined point
    bool inside = bsp(a, b, c, p);
    std::cout << "\nResult: Point P(" << px << ", " << py << ") is "
              << (inside ? "INSIDE" : "OUTSIDE") << " the triangle.\n";
  }

  std::cout
      << "\nThank you for using the Triangle Point Locator! Goodbye! 🌈\n";
  return 0;
}
