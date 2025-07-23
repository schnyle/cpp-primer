// Rewrite the program from the previous excersize to use a list. List the
// changes you needed to make.

#include <iostream>
#include <list> // changed
#include <string>

int main()
{
  std::list<std::string> strs; // changed
  std::string s;
  while (std::cin >> s)
  {
    strs.push_back(s);
  }

  for (auto iter = strs.begin(); iter != strs.end(); ++iter)
  {
    std::cout << *iter << " ";
  }
  std::cout << "\n";
}