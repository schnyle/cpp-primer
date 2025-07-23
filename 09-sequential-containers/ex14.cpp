// Write a program to assign the elements from a list of char* pointers to
// C-style character strings to a vector of strings.

#include <iostream>
#include <list>
#include <vector>
#include <string>

int main()
{
  std::list<const char *> l {"one", "two", "three"};

  std::vector<std::string> v;
  v.assign(l.begin(), l.end());

  for (auto &w : v)
  {
    std::cout << w << " ";
  }
  std::cout << "\n";
}