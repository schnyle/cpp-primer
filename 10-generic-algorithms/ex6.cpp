// Using fill_n, write a program to set a sequence of int values to 0.

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
  std::vector<int> v(10);
  std::iota(v.begin(), v.end(), 1);
  std::cout << "[";
  for (auto &x : v)
  {
    std::cout << x << " ";
  }
  std::cout << "]\n";

  std::fill_n(v.begin(), v.size(), 0);
  std::cout << "[";
  for (auto &x : v)
  {
    std::cout << x << " ";
  }
  std::cout << "]\n";
}