// Write a recursive function to print the contents of a vector.

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_v(vector<T> v)
{
  cout << v[0];
  if (v.size() > 1)
  {
    cout << " ";
    vector<T> sub_v (v.begin() + 1, v.end());
    print_v(sub_v);
  }
}

int main()
{
  vector<int> vi = {0, 1, 1, 2, 3, 5, 8};
  vector<char> vc = {'h', 'e', 'l', 'l', 'o'};

  print_v(vi);
  cout << endl;
  print_v(vc);
}