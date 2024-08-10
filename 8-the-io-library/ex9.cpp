// Use the function you wrote for the first exercise in section 8.1.2 to print
// the contents of an istringstream object.

#include <iostream>
#include <sstream>
#include <string>

std::istream &foo(std::istream &is)
{
  std::string word;
  while (is >> word)
    std::cout << word << ' ';

  is.clear();

  return is;
}

int main()
{
  std::istringstream ss("what is your favorite color?");
  foo(ss);
  std::cout << "\n";
}