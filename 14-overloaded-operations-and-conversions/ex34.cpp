// Define a function-object class to perform an if-then-else operation: The call
// operator for this class should take three parameters. It should test its
// first parameter and if that test succeeds, it should return its second
// parameter; otherwise, it should return its third parameter.

#include <iostream>

class MyClass
{
public:
  int operator()(bool b, int x, int y) { return b ? x : y; }
};

int main()
{
  MyClass mc;

  std::cout << mc(true, 420, 69) << "\n";
  std::cout << mc(false, 420, 69) << "\n";
}