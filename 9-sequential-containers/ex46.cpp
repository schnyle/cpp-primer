// Rewrite the previous exercise using a position and length to manage the
// strings. This time use only the insert function.

#include <iostream>
#include <string>

using std::string;

string &foo(string &name, const string pre, const string suf)
{
  name.insert(0, pre + " ");
  name.insert(name.size(), " " + suf);

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