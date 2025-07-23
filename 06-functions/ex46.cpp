// Would it be possible to define isShorter as a constexpr? If so, do so.
// If not, explain why not.

#include <iostream>
#include <string>

using std::cout;
using std::string;

constexpr bool isShorter(const string &s1, const string &s2)
{
  return s1.size() < s2.size(); // string is not constexpr: compile error
}

int main()
{ 
  const string s1 = "da";
  const string s2 = "sdhgjk";
  cout << ((isShorter(s1, s2)) ? s1 : s2) << '\n';
}