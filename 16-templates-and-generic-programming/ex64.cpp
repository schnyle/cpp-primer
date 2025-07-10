// Write a specialized verison of the template from the previous exercise to
// handle vector<const char*> and a program that uses this specialization.

#include <cstring>
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

template <>
int count(const std::vector<const char *> &data, const char *const &value)
{
  std::cout << "specialized\n";
  int res = 0;
  for (auto t : data)
  {
    res += std::strcmp(t, value) == 0 ? 1 : 0;
  }
  return res;
}

int main()
{
  const std::vector<const char *> vs{"how", "much", "wood",  "could",
                                     "a",   "wood", "chuck", "chuck"};
  const char *wood = "wood";
  std::cout << "vs: " << count(vs, wood) << "\n";
}