#include <iostream>

int main()
{
  std::cout << "Enter two integers:" << std::endl;
  int a, b;
  std::cin >> a >> b;
  std::cout << std::endl;
  while (a != b)
  {
    std::cout << a << std::endl;
    if (a < b)
      a++;
    else
      a--;
  }
  std::cout << b << std::endl;

  return 0;
}