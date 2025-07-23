// ex10: There is one problem with our vowel-counting program as we've
//       implemented it. It doesn't count capital letters as vowels. Write a
//       program that count both lower- and uppercase letters as the
//       appropriate vowel-that is, your program should count both 'a' and 'A'
//       as part of aCnt, and so forth
// ex11: Modify our vowel-counting program so that it also counts the number of
//       blank space, tabs, and newline reads.
// ex12: Modify out vowel-counting program so that it counts the number of
//       occurences of the following two-character sequences: ff, fl, and fi.

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
  char ch, last_ch;
  constexpr int ASCII_CHARS = 128;
  unsigned counts[ASCII_CHARS]{0};
  unsigned vCount = 0, sCount = 0, fCount = 0;

  while (cin.get(ch))
  {
    ++counts[ch];
    switch (tolower(ch))
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      ++vCount;
      break;
    case ' ':
    case '\t':
    case '\n':
      ++sCount;
      break;
    }

    if (last_ch == 'f' && (ch == 'f' || ch == 'l' || ch == 'i'))
      ++fCount;
    last_ch = ch;
  }

  for (int i = 0; i != ASCII_CHARS; ++i)
  {
    if (counts[i] != 0)
      cout << i << " (" << static_cast<char>(i) << ")" << " " << counts[i] << endl;
  }

  cout << endl
       << "vowels: " << vCount << endl;
  cout << "space chars: " << sCount << endl;
  cout << "ff, fl, fi: " << fCount << endl;
}