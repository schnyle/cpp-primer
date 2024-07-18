// Write a function to determine whether a string contains any capital letters.
// Write a function to change a string to all lowercase. Do the parameters you
// used in these functions have the same type? If so, why? If not, why?

#include <iostream>
#include <cctype>

using namespace std;

bool contains_upper_case(const string &s)
{
  for (auto &c : s)
    if (isupper(c)) return true;
  return false;
}

void make_screaming(string &s)
{
  for (auto &c : s)
    c = toupper(c);
}

int main()
{
  cout << (contains_upper_case("hello") ? "yes " : "no ") << (contains_upper_case("Hello") ? "yes " : "no ") << endl;

  string s = "how are you?";
  make_screaming(s);
  cout << s << endl;

  return 0;
}