// Write a program to read a sequence of strings from the standard input into
// a deque. Use iterators to write a loop to print the elements in the deque.

#include <iostream>
#include <deque>
#include <string>

int main()
{
  std::deque<std::string> strs;
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