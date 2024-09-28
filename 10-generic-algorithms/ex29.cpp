// Write a program using stream iterators to read a text file into a vector
// of strings.

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>

int main()
{
  std::ifstream in("ex29.cpp");
  std::istream_iterator<std::string> str_it(in), eof;
  std::vector<std::string> res(str_it, eof);

  for (auto &x : res)
  {
    std::cout << x << "\n";
  }
}