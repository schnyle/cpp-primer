// Copy a vector that holds the values from 1 to 9 inclusive, into three other
// containers. Use an inserter, a back_inserter, and a front_inserter,
// respectively to add elements to these containers. Predict how the output
// sequence varies by the kind of inserter and verify your predictions by
// running your programs.

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <numeric>

std::ostream &p(std::ostream &os, std::list<int> &v)
{
  for (auto &x : v)
  {
    os << x << " ";
  }
  return os;
}

int main()
{
  std::list<int> v(9);
  std::iota(v.begin(), v.end(), 1);

  std::cout << "v: ";
  p(std::cout, v) << "\n";

  std::list<int> r1;
  std::copy(v.cbegin(), v.cend(), std::inserter(r1, r1.begin()));
  std::cout << "inserter: ";
  p(std::cout, r1) << "\n";

  std::list<int> r2;
  std::copy(v.cbegin(), v.cend(), std::back_inserter(r2));
  std::cout << "back inserter: ";
  p(std::cout, r2) << "\n";

  std::list<int> r3;
  std::copy(v.cbegin(), v.cend(), std::front_inserter(r3));
  std::cout << "front inserter: ";
  p(std::cout, r3) << "\n";
}