#include <iostream>
#include <vector>

using namespace std;

void original()
{
  vector<int> ivec(10);
  vector<int>::size_type cnt = ivec.size();
  for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
    ivec[ix] = cnt;

  cout << "original:" << endl;
  for (auto &x : ivec)
    cout << x << ' ';
  cout << endl;
}

void mine()
{
  vector<int> ivec(10);
  vector<int>::size_type cnt = ivec.size();
  for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
    ivec[ix] = cnt;

  cout << "mine:" << endl;
  for (auto &x : ivec)
    cout << x << ' ';
  cout << endl;
}

int main()
{
  original();
  mine();
  
  cout << "No difference?" << endl;

  return 0;
}