// Using the classes defined in the first exercise, rewrite the following code
// to convert the expression *pa to the type C&:
// if (C *pc = dynamic_cast<C *>(pa))
// {
//   // use C's memers
// }
// else
// {
//   // use A's members
// }

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
  A *pa = new A;

  try
  {
    C &pc = dynamic_cast<C &>(*pa);
    // use C's members
  }
  catch (...)
  {
    // use A's members
  }
}