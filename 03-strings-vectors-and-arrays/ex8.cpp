#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  cin >> s;

  // I prefer this first method since I often forget to increment
  // the index in the second method.
  string s1 = s;
  for (auto &c : s1)
    c = 'X';

  cout << s1 << endl;

  string s2 = s;
  size_t i = 0;
  while (i < s2.size())
  {
    s2[i] = 'Y';
    i++;
  }

  cout << s2 << endl;

  return 0;
}