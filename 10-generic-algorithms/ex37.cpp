// Given a vector that has ten elements, copy the elements from positions 3
// through 7 in reverse order to a list.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

int main()
{
  std::vector<int> v(10);
  std::iota(v.begin(), v.end(), 1);
  
  for (auto &x : v)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";

  std::list<int> res;
  std::copy(v.crbegin() + 3, v.crend() - 2, std::back_inserter(res));

  for (auto &x : res)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
}