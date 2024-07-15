#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
  string s;
  getline(cin, s);

  for (auto &c : s)
    if (!ispunct(c))
      cout << c;
  cout << endl;

  return 0;
}