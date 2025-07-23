#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> iv = {0, 1, 2, 3, 4, 5};

  for (auto &x : iv)
    x *= (x % 2 == 0) ? 1 : 2;

  for (auto &x : iv)
    cout << x << ' ';
  cout << endl;

  return 0;
}

