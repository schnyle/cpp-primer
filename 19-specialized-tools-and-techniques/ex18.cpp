// Write a function that uses count_if to count how many empty strings there are
// in a given vector.

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main()
{
  std::vector<std::string> v{"notempty", "", "alsonotempty", "", "yo"};

  bool (std::string::*p)() const noexcept = &std::string::empty;
  std::function<bool(const std::string &)> f = p;

  std::cout << std::count_if(v.cbegin(), v.cend(), f) << "\n";
}