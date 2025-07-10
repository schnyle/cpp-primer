// Define a function template to count the number of ocurrences of a given value
// in a vector. Test your program by passing it a vector of doubles, a vector of
// ints, and a vector of strings.

#include <iostream>
#include <string>
#include <vector>

template <typename T> int count(const std::vector<T> &data, const T &value)
{
  int res = 0;
  for (const T &t : data)
  {
    res += t == value ? 1 : 0;
  }
  return res;
}

int main()
{
  const std::vector<int> vi{1, 1, 2, 3, 5, 8};
  std::cout << "vi: " << count(vi, 1) << "\n";

  const std::vector<double> vd{1.8, 9.8, 3.0, 4.1, 9.8, 3.3, 9.8};
  std::cout << "vd: " << count(vd, 9.8) << "\n";

  const std::vector<std::string> vs{"how", "much", "wood",  "could",
                                    "a",   "wood", "chuck", "chuck"};
  const std::string wood = "wood";
  std::cout << "vs: " << count(vs, wood) << "\n";
}