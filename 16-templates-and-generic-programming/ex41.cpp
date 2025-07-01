// Write a version of sum with a return type that is guaranteed to be large
// enough to hold the result of the addition.

template <typename T1, typename T2>
auto sum(const T1 &a, const T2 &b) -> decltype(a + b)
{
  return a + b;
}

#include <iostream>

int main()
{
  signed char a = 100, b = 100;
  auto s = sum(a, b);
}