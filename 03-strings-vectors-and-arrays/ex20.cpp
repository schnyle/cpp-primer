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
  for (i = 0; i < v.size() - 1; i++)
    cout << v[i] + v[i + 1] << endl;

  cout << "pairs:\n";
  size_t v_size = v.size();
  for (i = 0; i < v_size / 2; i++)
    cout << v[i] + v[v_size - i - 1] << endl;
  if (v_size % 2 == 1)
    cout << v[i] << endl;

  return 0;
}