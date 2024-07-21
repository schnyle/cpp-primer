// Rewrite the isShorter function from 6.2.2 to be inline.

#include <iostream>
#include <string>

using std::cout;
using std::string;

inline bool isShorter(const string &s1, const string &s2)
{
  return s1.size() < s2.size();
}

int main()
{ 
  const string s1 = "da";
  const string s2 = "sdhgjk";
  cout << ((isShorter(s1, s2)) ? s1 : s2) << '\n';
}