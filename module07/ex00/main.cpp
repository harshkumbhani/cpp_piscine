#include "Utils.hpp"
#include "whatever.hpp"

void testSwap() {
  int a = 42;
  int b = -128;
  printLog("Testing Swapping\n", HEADER);

  printLog("INT data Type\n", INFO);
  printLog("Before swapping:", WARNING);
  std::cout << "(a, b) : (" << a << ", " << b << ")" << std::endl;
  ::swap(a, b);
  printLog("After swapping:", SUCCESS);
  std::cout << "(a, b) : (" << a << ", " << b << ")" << std::endl;

  std::string str1 = "Conny";
  std::string str2 = "Tiggy";
  printLog("STRING data Type\n", INFO);
  printLog("Before swapping:", WARNING);
  printLog("(str1, str2) : (" + str1 + ", " + str2 + ")");
  ::swap(str1, str2);
  printLog("After swapping:", SUCCESS);
  printLog("(str1, str2) : (" + str1 + ", " + str2 + ")\n");
}

void testMin_Max() {
  int a = 42;
  int b = -128;
  printLog("Testing Min-Max\n", HEADER);

  printLog("INT data Type\n", INFO);
  std::cout << "min of (" << a << ", " << b << ") is " << ::min(a, b)
            << std::endl;
  std::cout << "max of (" << a << ", " << b << ") is " << ::max(a, b)
            << std::endl;

  std::string str1 = "String_A";
  std::string str2 = "String_B";
  printLog("\nSTRING data Type\n", INFO);
  printLog("min of (" + str1 + ", " + str2 + ") is " + ::min(str1, str2),
           SUCCESS);
  printLog("max of (" + str1 + ", " + str2 + ") is " + ::max(str1, str2),
           SUCCESS);
}

void testPdf() {
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

int main() {

  //testPdf();
  testSwap();
  testMin_Max();
  return 0;
}
