// Write a program that initializes a string from a vector<char>.

#include <iostream>
#include <string>
#include <vector>

int main()
{
  std::vector<char> v {'h', 'e', 'l', 'l', 'o'};
  std::string s(v.begin(), v.end());
  std::cout << s << "\n";
}