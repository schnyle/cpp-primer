// 18 Given the classes from page 612 and 613, and assuming each object has the
//    type specified in the comments, determine which of these assignmnets are
//    legal. Explain why those that are illegal aren't allowed:
// 19 Assume that each of the classes from page 612 and 613 has a member
//    function of the form
//      void memfcn(Base &b) { b = *this; }
//    For each class, determine whether this funciton would be legal.

class Base
{
public:
  void memfcn(Base &b) { b = *this; }

protected:
  int prot_mem;

private:
  char priv_mem;
};

struct Pub_Derv : public Base
{
  void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base
{
  void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base
{
  void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
  void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : public Prot_Derv
{
  void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv
{
  void memfcn(Base &b) { b = *this; }
};

int main()
{
  Pub_Derv d1;
  Priv_Derv d2;
  Prot_Derv d3;
  Derived_from_Public dd1;
  Derived_from_Private dd2;
  Derived_from_Protected dd3;

  Base *p = &d1;
  p = &d2;
  p = &d3;
  p = &dd1;
  p = &dd2;
  p = &dd3;
}