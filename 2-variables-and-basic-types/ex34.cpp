#include <iostream>

int main()
{
  int i = 0, &r = i;
  auto a = r; // int

  const int ci = i, &cr = ci;
  auto b = ci; // int
  auto c = cr; // int
  auto d = &i; // int*
  auto e = &ci; // const int*
  auto &g = ci; // const int&

  a = 42;
  b = 42;
  c = 42;
  d = 42; // error
  e = 42; // error
  g = 42; // error
}