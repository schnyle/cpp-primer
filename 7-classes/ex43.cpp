// Assume we have a class NoDefault that has a constructor that takes an int,
// but has no default constructor. Define a class C that has a member of type
// NoDefault. Define the default constructor for C.

#include <vector>

class NoDefault
{
public:
  NoDefault(int i);
};

class C
{
  NoDefault nd;
public:
  C() : nd(0) {}
};

int main()
{
  std::vector<NoDefault> v(10);
}