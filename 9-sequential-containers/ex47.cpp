// Write a program that finds each numeric character and then each alphabetic
// character in the string "ab2c3d7R4E6". Write two versions of the program. The
// first should use find_first_of, and the second find_first_not_of.

#include <iostream>
#include <string>

using std::string;

const string numeric = "0123456789";
const string alphabetic = "abcdefghijklmnopqrstuvwxyz"
                          "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void foo1(const std::string &s)
{
  string::size_type pos = 0;
  while ((pos = s.find_first_of(numeric, pos)) != string::npos)
  {
    std::cout << s.at(pos) << " ";
    ++pos;
  }
  std::cout << "\n";

  pos = 0;
  while ((pos = s.find_first_of(alphabetic, pos)) != string::npos)
  {
    std::cout << s.at(pos) << " ";
    ++pos;
  }
  std::cout << "\n";
}

void foo2(const std::string &s)
{
  string::size_type pos = 0;
  while ((pos = s.find_first_not_of(alphabetic, pos)) != string::npos)
  {
    std::cout << s.at(pos) << " ";
    ++pos;
  }
  std::cout << "\n";

  pos = 0;
  while ((pos = s.find_first_not_of(numeric, pos)) != string::npos)
  {
    std::cout << s.at(pos) << " ";
    ++pos;
  }
  std::cout << "\n";
}

int main()
{
  const string s = "ab2c3d7R4E6";
  foo1(s);
  std::cout << "\n";
  foo2(s);
}