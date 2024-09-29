// Use find to find the last element in a list of ints with value 0.

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> v{0, 1, 2, 3, 4, 5, 0, 7, 8};

  auto last_zero = std::find(v.crbegin(), v.crend(), 0);
  auto index = last_zero.base() - 1 - v.cbegin();
  std::cout << "index: " << index << "\n";
}