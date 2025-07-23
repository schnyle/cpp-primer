// Write a function that takes a pair of iterators to a vector<int> and an int
// value. Look for that value in the range and return a bool indicating whether
// it was found.

#include <iostream>
#include <vector>

bool does_exist(std::vector<int>::iterator begin, std::vector<int>::iterator end, int val)
{
  while (begin != end)
  {
    if (*begin == val)
      return true;
    ++begin;
  }
  return false;
}

int main()
{
  std::vector<int> v {1, 2, 3, 4};

  bool res1 = does_exist(v.begin(), v.end(), 3);
  std::cout << "res1: " << res1 << "\n";

  bool res2 = does_exist(v.begin(), v.end(), 6);
  std::cout << "res2: " << res2 << "\n";

  return 0;
}
