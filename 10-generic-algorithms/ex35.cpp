// Now print the elements in reverse order using ordinary iterators.

#include <iostream>
#include <vector>
#include <numeric>

int main()
{
  std::vector<int> v(10);
  std::iota(v.begin(), v.end(), 1);

  for (auto it = v.cend(); it != v.cbegin(); --it)
  {
    std::cout << *(it - 1) << " ";
  }
  std::cout << "\n";
}