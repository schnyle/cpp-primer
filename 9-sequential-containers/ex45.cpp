// Write a function that takes a string representing a name and two other
// strings representing a prefix, such as "Mr." or "Ms." and a suffix, such as 
// "Jr." or "III". Using iterators and the insert and append functions, generate
// and return a new string with the suffix and prefix added to the given name.

#include <iostream>
#include <string>

using std::string;

string &foo(string &name, const string pre, const string suf)
{
  name.insert(0, pre + " ");
  name.append(" " + suf);

  return name;
}

int main()
{
  string name = "Fluffington";
  string pre = "Prof.";
  string suf = "III (PhD.)";
  
  name = foo(name, pre, suf);
  std::cout << name << "\n";
}