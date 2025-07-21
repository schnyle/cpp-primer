// Using the hierarchy in exercise 18.22 along with the class D defined below,
// and assuming each class defined a default constructor, which, if any, of the
// following conversions are not permitted?

#include <iostream>

class A
{
public:
  A() { std::cout << "A\n"; }
};

class B : public A
{
public:
  B() { std::cout << "B\n"; }
};

class C : public B
{
public:
  C() { std::cout << "C\n"; }
};

class X
{
public:
  X() { std::cout << "X\n"; }
};

class Y
{
public:
  Y() { std::cout << "Y\n"; }
};

class Z : public X, public Y
{
public:
  Z() { std::cout << "Z\n"; }
};

class MI : public C, public Z
{
public:
  MI() { std::cout << "MI\n"; }
};

class D : public X, public C
{
public:
  D() { std::cout << "D\n"; }
};

int main()
{
  D *pd = new D;

  X *px = pd; // valid
  A *pa = pd; // valid
  B *pb = pd; // valid
  C *pc = pd; // valid

  delete pd;
}