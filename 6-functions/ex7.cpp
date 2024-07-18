// Write a function that returns 0 when it is first called and then generates
// numbers in sequence when it is called again.

#include <iostream>

using namespace std;

long int next_fib()
{
  static int last = 0;
  static int curr = 1;
  static bool first = true;

  long int res = curr + last;
  last = curr;
  curr =  res;

  return res;
}

int main()
{
  cout << "0 1 ";

  int i = 0;
  int max = 10;
  while (i++ < max)
    cout << next_fib() << ' ';
  cout << endl;

  return 0;
}