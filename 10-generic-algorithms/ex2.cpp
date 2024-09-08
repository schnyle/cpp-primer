// Repeat the previous program, but read values into a list of strings.

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

int get_count(std::string val, std::list<std::string> v)
{
  return std::count(v.cbegin(), v.cend(), val);
}

int main()
{
  std::string s;
  std::list<std::string> v;  

  while (std::cin >> s)
  {
    v.push_back(s);
  }

  std::cout << get_count(s, v) << "\n";
}