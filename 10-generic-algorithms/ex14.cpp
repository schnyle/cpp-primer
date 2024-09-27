// Write a lambda that takes two ints and returns their sum.

#include <iostream>

int main()
{

  int a = 6;
  int b = 12;

  std::cout << "res: " << [a, b]() -> int { return a + b; }() << "\n";
  

}