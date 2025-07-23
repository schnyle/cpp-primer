#include <iostream>
#include <cstring>

using namespace std;

void compare_strings(string &s1, string &s2)
{
  if (s1.size() > s2.size())
  {
    cout << s1 << " is longer." << endl;
    return;
  }
  if (s2.size() > s1.size())
  {
    cout << s2 << " is longer." << endl;
    return;
  }

  auto it_s1 = s1.begin(), it_s2 = s2.begin();
  for (; it_s1 != s1.end() && it_s2 != s2.end(); it_s1++, it_s2++)
  {
    if (*it_s1 < *it_s2)
    {
      cout << s2 << " is larger." << endl;
      return;
    }
    if (*it_s1 > *it_s2)
    {
      cout << s1 << " is larger." << endl;
      return;
    }
  }

  cout << "Equal." << endl;
}

void compare_c_strings(const char s1[], const char s2[])
{
  const char *p1 = s1;
  const char *p2 = s2;
  while (*p1 != '\0' && *p2 != '\0')
  {
    if (*p1 < *p2)
    {
      cout << s2 << " is larger." << endl;
      return;
    }
    if (*p1 > *p2)
    {
      cout << s1 << " is larger." << endl;
      return;
    }

    p1++;
    p2++;
  }

  if (*p1 == '\0' && *p2 == '\0')
    cout << "Equal." << endl;
  if (*p1 == '\0')
    cout << s2 << " is longer." << endl;
  else
    cout << s1 << " is longer." << endl;
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  compare_strings(s1, s2);
  compare_c_strings(s1.c_str(), s2.c_str());

  return 0;
}