#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> v {0, 1, 2, 3, 4, 5};

  for (auto it = v.begin(); it != v.end(); ++it)
    *it *= *it;

  cout << '[';
  for (auto i : v)
    cout << i << " ";
  cout << "]\n";

  return 0;
}