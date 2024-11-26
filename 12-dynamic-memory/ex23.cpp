// Write a program to concatenate two string literals, putting the result in a
// dynamically allocated array of char. Write a program to concatenate two
// library strings that have the same value as the literals used in the first
// program.

#include <cstring>
#include <iostream>
#include <memory>
#include <string>

std::unique_ptr<char[]> foo1(const char *s1, const char *s2)
{
  const auto length1 = std::strlen(s1);
  const auto length2 = std::strlen(s2);

  std::unique_ptr<char[]> res(new char[length1 + length2 + 1]);

  for (size_t i = 0; i < length1; ++i)
  {
    res[i] = s1[i];
  }
  for (size_t i = 0; i < length2; ++i)
  {
    res[length1 + i] = s2[i];
  }
  res[length1 + length2] = '\0';

  return res;
}

std::string foo2(const std::string &s1, const std::string &s2)
{
  return s1 + s2;
}

int main()
{
  const char *cp1 = "hello";
  const char *cp2 = " world";
  const auto res1 = foo1(cp1, cp2);
  std::cout << res1.get() << "\n";

  const std::string s1(cp1);
  const std::string s2(cp2);
  std::cout << foo2(s1, s2) << "\n";
}