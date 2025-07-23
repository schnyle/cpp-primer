// Write a function that takes an initializer_list<int> and produces the sum of
// the elements in the list.

#include <iostream>
#include <initializer_list>

using namespace std;

int get_sum(initializer_list<int> il)
{
  int sum = 0;
  for (auto &x : il)
    sum += x;
  return sum;
}

int main()
{
  int sum = get_sum({0, 1, 1, 2, 3, 5, 8, 13});

  cout << sum << endl;
}