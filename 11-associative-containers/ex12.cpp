// Write a program to read a sequence of strings and ints, storing each into a
// pair. Store the pairs in a vector.

#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

int main()
{
  std::string input("string1 0 string2 4 string3 8 string4 16");
  std::istringstream iss(input);

  std::vector<std::pair<std::string, int>> res;

  std::string word;
  int integer;
  while (iss >> word >> integer)
  {
    res.emplace_back(word, integer);
  }

  for (auto &[w, i] : res)
  {
    std::cout << w << " " << i << "\n";
  }
}