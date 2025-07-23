// Rewrite the previous program to return an iterator to the requested element.
// Note that the program must handle the case where the element is not found.

#include <iostream>
#include <vector>

using It = std::vector<int>::iterator;

It does_exist(It begin, It end, int val)
{
  while (begin != end)
  {
    if (*begin == val)
      return begin;
    ++begin;
  }
  return end;
}

int main()
{
  std::vector<int> v {1, 2, 3, 4};

  It res1 = does_exist(v.begin(), v.end(), 3);
  std::cout << "res1: " << *res1 << "\n";

  It res2 = does_exist(v.begin(), v.end(), 6);
  std::cout << "res2: " << *res2 << "\n";

  return 0;
}
