// Given the following class hierarchy, in which each class defines a default
// constructor, what is the order of constructor execution for the following
// definition?

// A -> B -> C -> X -> Y -> Z -> MI

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

int main() { MI mi; }