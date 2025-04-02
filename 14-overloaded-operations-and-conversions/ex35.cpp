// Write a class like PrintString that reads a line of input from an istream and
// returns a string representing what was read. If the read fails, return the
// empty string.

#include <iostream>

class ReadString
{
public:
  ReadString(std::istream &i = std::cin) : is(i) {}
  std::string operator()()
  {
    std::string res;
    is >> res;
    if (!is)
    {
      return "";
    }
    return res;
  }

private:
  std::istream &is;
};

int main()
{
  ReadString reader;
  std::cout << reader();
};