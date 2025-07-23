#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<unsigned> scores(11, 0);
  unsigned grade;
  auto it = scores.begin();
  while (cin >> grade)
  {
    if (grade <= 100)
      ++(*(it + grade / 10));
  }

  for (auto ui : scores)
    cout << ui << ' ';
  cout << endl;

  return 0;
}