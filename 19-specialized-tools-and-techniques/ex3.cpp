// Given the following class hierarchy in which each class defines a public
// default constructor and virtual destructor:

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

class D : public B, public A
{
public:
  D() = default;
  virtual ~D() = default;
};

// which, if any, of the following dynamic_casts fail?

int main()
{
  // good - C is a B
  A *pa = new C;
  B *pb = dynamic_cast<B *>(pa);

  // bad - B is not a C
  B *pb2 = new B;
  C *pc = dynamic_cast<C *>(pb2);

  // bad - base class of D, A, is ambiguous
  A *pa2 = new D;
  B *pb = dynamic_cast<B *>(pa);
}