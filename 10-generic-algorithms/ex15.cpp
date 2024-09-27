// Write a lambda that captures an int from its enclosing function and takes an 
// int parameter. The lambda should return the sum of the captured int and the
// int parameter.

#include <iostream>

int add(int a, int b)
{
  return [a](int b){ return a + b; }(b);
}

int main()
{
  std::cout << add(4, 7) << "\n";
}