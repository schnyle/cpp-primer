// In addition to unqiue, the library defined a function names unique_copy that
// takes a third iterator denoting a destination into which to copy the unique
// elements. Write a program that uses unique_copy to copy the unique elements
// from a vector into an initially empty list.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

int main()
{
  std::vector<int> v{0, 1, 1, 2, 3, 3, 4, 5, 5};

  std::vector<int> r;
  std::unique_copy(v.cbegin(), v.cend(), std::inserter(r, r.begin()));

  for (auto &x : r)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
}