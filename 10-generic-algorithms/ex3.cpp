// Use accumulate to sum the elements in a vector<int>.

#include <iostream>
#include <vector>
#include <numeric>

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

  auto res = std::accumulate(v.cbegin(), v.cend(), 0);
  std::cout << "res: " << res << "\n";
}