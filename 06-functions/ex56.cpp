// ex54: Write a declaration for a function that takes two int parameters and
//       returns an int, and declare a vector whose elements have this function
//       pointer type.
// ex55: Write four functions that add, subtract, multiply, and divide two int
//       values. Store pointers to these functions in your vector from the
//       previous exercise.
// ex56: Call each element in the vector and print their result.

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int f(int, int);
vector<decltype(f) *> v;
// vector<int(*)(int, int)> v;

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mult(int x, int y) { return x * y; }
int divd(int x, int y) { return x / y; } // yes yes y != 0 stuff

int main()
{
  v.push_back(add);
  v.push_back(sub);
  v.push_back(mult);
  v.push_back(divd);

  int x = 5;
  int y = 3;
  cout << v[0](x, y) << '\n';
  cout << v[1](x, y) << '\n';
  cout << v[2](x, y) << '\n';
  cout << v[3](x, y) << '\n';
}