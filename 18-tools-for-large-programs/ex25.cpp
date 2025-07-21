// Assume we have two base classes, Base 1 and Base 2, each of which defines a
// virtual member named print and a virtual destructor.

#include <iostream>

class Base1
{
public:
  virtual void print() { std::cout << "print Base1\n"; }

  virtual ~Base1() { std::cout << "~Base1\n"; }
};

class Base2
{
public:
  virtual void print() { std::cout << "print Base2\n"; }

  virtual ~Base2() { std::cout << "~Base2\n"; }
};

// From these base classes we derive the following classes, each of which
// redefines the print function:

class D1 : public Base1
{
public:
  void print() override { std::cout << "print D1\n"; }
};

class D2 : public Base2
{
public:
  void print() override { std::cout << "print D2\n"; }
};

class MI : public D1, public D2
{
  void print() override { std::cout << "print MI\n"; }
};

// Using the following pointers, determine which function is used in each call:

int main()
{
  Base1 *pb1 = new MI;
  Base2 *pb2 = new MI;
  D1 *pd1 = new MI;
  D2 *pd2 = new MI;

  pb1->print();
  pd1->print();
  pd2->print();
  delete pb2;
  std::cout << "\n";
  delete pd1;
  std::cout << "\n";
  delete pd2;
}