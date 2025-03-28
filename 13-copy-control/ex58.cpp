// Write versions of class Foo with print statements in their sorted functions
// to test your answers to the previous two exercises.

#include <algorithm>
#include <iostream>
#include <vector>

class Foo
{
public:
  Foo sorted() &&;
  Foo sorted() const &;

  std::vector<int> data = std::vector<int>{1, 8, 3, 7, 0, 5};
};

Foo Foo::sorted() &&
{
  std::cout << "rvalue\n";
  std::sort(data.begin(), data.end());
  return *this;
}

// Foo Foo::sorted() const &
// {
//   std::cout << "const lvalue\n";
//   Foo ret(*this);
//   std::sort(ret.data.begin(), ret.data.end());
//   return ret;
// }

// ex56 - infinite loop
// Foo Foo::sorted() const &
// {
//   std::cout << "const lvalue\n";
//   Foo ret(*this);
//   return ret.sorted();
// }

// ex57 - call rvalue version within lvalue
Foo Foo::sorted() const &
{
  std::cout << "const lvalue\n";
  return Foo(*this).sorted();
}

int main()
{
  Foo foo;
  foo.sorted();

  for (auto &x : foo.data)
  {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  // auto y = std::move(foo).sorted(); // rvalue
}