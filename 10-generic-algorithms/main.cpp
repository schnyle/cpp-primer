#include <iostream>
#include <vector>
#include <string>

int main()
{
  size_t v1 = 43;
  auto f = [v1] { return ++v1; };
  v1 = 0;
  auto j = f();

  std::cout << "j: " << j << "\n";
  std::cout << "v1: " << v1 << "\n";
}