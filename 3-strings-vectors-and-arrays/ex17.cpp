#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned WORDS_PER_LINE = 8;

int main()
{
  vector<string> v;
  string s;
  while (cin >> s)
    v.push_back(s);

  for (auto &s : v)
    for (auto &c : s)
      c = toupper(c);

  unsigned i = 0;
  for (auto w : v)
  {
    cout << w << ' ';
    if ((i + 1) % WORDS_PER_LINE == 0)
      cout << '\n';
    i++;
  }

  cout << endl;

  return 0;
}