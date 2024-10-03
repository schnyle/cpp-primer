// There are at least three ways to create the pairs in the program for the
// previous exercise. Write three versions of that program, creating the pairs
// in each way. Explain which form you think is easiest to write and understand,
// and why.

#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

void v1()
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

void v2()
{
  std::string input("string1 0 string2 4 string3 8 string4 16");
  std::istringstream iss(input);

  std::vector<std::pair<std::string, int>> res;

  std::string word;
  int integer;
  while (iss >> word >> integer)
  {
    std::pair p(word, integer);
    res.push_back(p);
  }

  for (auto &[w, i] : res)
  {
    std::cout << w << " " << i << "\n";
  }
}

void v3()
{
  std::string input("string1 0 string2 4 string3 8 string4 16");
  std::istringstream iss(input);

  std::vector<std::pair<std::string, int>> res;

  std::string word;
  int integer;
  while (iss >> word >> integer)
  {
    auto p = std::make_pair(word, integer);
    res.push_back(p);
  }

  for (auto &[w, i] : res)
  {
    std::cout << w << " " << i << "\n";
  }
}
int main()
{
  v1();
  std::cout << "\n";
  v2();
  std::cout << "\n";
  v3();
}