#include <iostream>
#include <string>

using namespace std;

void concat_stdin()
{
  string buf;
  string word;
  while (cin >> word)
    buf += word;
  cout << buf << endl;
}

void concat_stdin_spaces()
{
  string buf;
  string word;
  while (cin >> word)
    buf += word + ' ';
  cout << buf << endl;
}

int main()
{
  // concat_stdin();
  concat_stdin_spaces();

  return 0;
}