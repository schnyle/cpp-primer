// Use bind and check_size to find the first element in a vector of ints that
// has a value greater than the length of the specified string value.

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <functional>

using namespace std::placeholders;

bool check_size(const std::string &s, std::string::size_type sz)
{
  return s.size() >= sz;
}

int main()
{
  std::vector<int> vi(10);
  std::iota(vi.begin(), vi.end(), 1);

  const std::string s = "hello";

  auto check_size_s = std::bind(check_size, s, _1);

  auto res = *std::find_if(vi.cbegin(), vi.cend(), [&](int i) { return !check_size_s(i); });
  std::cout << "res: " << res << "\n";
}