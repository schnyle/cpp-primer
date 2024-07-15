#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> v;
  int i;
  while (cin >> i)
    v.push_back(i);

  cout << '[';
  for (auto e : v)
    cout << e << ' ';
  cout << "]\n";

  cout << "adjacent:\n";
  for (auto it = v.begin(); it != v.end() - 1; it++)
    cout << *it + *(it + 1) << endl;

  cout << "pairs:\n";
  auto bit = v.begin();
  auto eit = v.end() - 1;
  while (eit - bit > 0)
  {
    cout << *eit + *bit << endl;
    eit--;
    bit++;
  }
  if (eit == bit)
    cout << *bit << endl;

  return 0;
}