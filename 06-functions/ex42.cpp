// Give the third parameter of make_plural a default argument of 's'. Test your
// program by printing singular and plural versions of the words success and
// failure.

#include <iostream>
#include <string>

using std::cout;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
  return (ctr > 1) ? word + ending : word;
}

int main()
{
  cout << make_plural(1, "success") << '\n';
  cout << make_plural(1, "failure") << '\n';
  cout << make_plural(2, "success") << '\n';
  cout << make_plural(2, "failure") << '\n';
}