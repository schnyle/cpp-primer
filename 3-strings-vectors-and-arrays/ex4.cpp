#include <iostream>
#include <string>

using namespace std;

void test_equality(string s1, string s2)
{
  if (s1 == s2)
  {
    cout << "Strings are equal.\n";
    return;
  }
  if (s1 > s2)
    cout << s1;
  else
    cout << s2;
  cout << " is larger.\n";  
}

void test_length(string s1, string s2)
{
  if (s1.size() == s2.size())
  {
    cout << "Strings are same length.\n";
    return;
  }
  if (s1.size() > s2.size())
    cout << s1;
  else
    cout << s2;
  cout << " is longer.\n";
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;

  test_equality(s1, s2);
  test_length(s1, s2);

  return 0;
}