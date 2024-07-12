#include <iostream>

int main()
{ 
  int s = 0, v = 0;
  while (std::cin >> v)
    s += v;
  std::cout << s << std::endl;
  return 0;
}