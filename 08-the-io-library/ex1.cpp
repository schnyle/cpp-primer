// Write a function that takes and returns an istream&. The function should
// read the stream until it hits end-of-file. The function should print what it
// reads to the standard output. Reset the stream so that it is valid before
// returning the stream.

#include <iostream>
#include <string>

std::istream &foo(std::istream &is)
{
  // std::cout << std::iostream::iostate;
  std::string word;
  while (is >> word)
    std::cout << word << ' ';

  is.clear();

  return is;
}

int main()
{
  foo(std::cin);
}