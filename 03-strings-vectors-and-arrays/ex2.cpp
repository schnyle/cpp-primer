#include <iostream>
#include <string>

using namespace std;

void read_lines()
{
  string line;
  while (getline(cin, line))
    if (!line.empty())
      cout << line << endl;
}

void read_words()
{
  string word;
  while (cin >> word)
    cout << word << endl;
}

int main()
{
  // read_lines();
  read_words();

  return 0;
}