// The algorithm header defines a function named count that, like find, takes a
// pair of iterators and a value. cont returns a count of how often that value
// appears. Read a sequence of ints into a vector and print the count of how
// many elements had a given value.

#include <algorithm>
#include <iostream>
#include <vector>

int get_count(int val, std::vector<int> v)
{
  return std::count(v.cbegin(), v.cend(), val);
}

int main()
{
  int i;
  std::vector<int> v;  

  while (std::cin >> i)
  {
    v.push_back(i);
  }

  std::cout << get_count(i, v) << "\n";
}