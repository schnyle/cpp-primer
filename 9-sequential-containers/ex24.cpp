// Write a program that fetches the first element in a vector using at, the
// subscript operator, front, and begin. Test your program on an empty vector.

#include <iostream>
#include <vector>

void foo(std::vector<int> &v)
{
  auto v1 = v.at(0);
  auto v2 = v[0];
  auto v3 = v.front();
  auto v4 = *v.begin();

  std::cout << v1 << " " << v2 << " " << v3 << " " << v4 << "\n";
}

int main()
{
  std::vector<int> v = {4, 2, 0};

  foo(v);

  std::vector<int> m;

  foo(m);
}