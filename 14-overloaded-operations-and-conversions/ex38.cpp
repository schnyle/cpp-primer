// Write a class that tests whether the length of a given string matches a given
// bound. Use that object to write a program to report how many words in an
// input file are of sizes 1 through 10 inclusive.

#include <fstream>
#include <iostream>
#include <string>

class StringLength
{
public:
  StringLength(const size_t n) : sz(n) {}

  bool operator()(const std::string &s) { return s.size() == sz; }

private:
  size_t sz;
};

int main()
{
  int count = 0;
  std::ifstream ifs("ex38.cpp");

  std::string w;
  while (ifs >> w)
  {
    for (int i = 1; i <= 10; ++i)
    {
      if (StringLength(i)(w))
      {
        ++count;
        break;
      }
    }
  }

  std::cout << "count: " << count << "\n";
}