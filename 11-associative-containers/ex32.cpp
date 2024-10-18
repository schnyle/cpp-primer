// Using the multimap from the previous exercise, write a program to print the
// list of authors and their works alphabetically.

#include <iostream>
#include <map>
#include <string>

int main()
{
  std::multimap<std::string, std::string> author_works{
      {"Abe", "Abe's Book"},
      {"Dabe", "Dabe's book"},
      {"Ave", "Daaaah"},
      {"Flabe", "I hate writing"}};

  for (auto &p : author_works)
  {
    std::cout << p.first << ": " << p.second << "\n";
  }
}