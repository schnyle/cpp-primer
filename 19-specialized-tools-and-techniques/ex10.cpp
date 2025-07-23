// Given the following class hierarchy in which each class defines a public
// default constructor and virtual destructor, which type name do the following
// statements print?

#include <iostream>

class A
{
public:
  A() = default;
  virtual ~A() = default;
};

class B : public A
{
public:
  B() = default;
  virtual ~B() = default;
};

class C : public B
{
public:
  C() = default;
  virtual ~C() = default;
};

int main()
{
  A *pa = new C;
  std::cout << typeid(pa).name() << std::endl; // P1A

  C cobj;
  A &ra = cobj;
  std::cout << typeid(&ra).name() << std::endl; // P1A

  B *px = new B;
  A &ra2 = *px;
  std::cout << typeid(ra2).name() << std::endl; // 1B
}