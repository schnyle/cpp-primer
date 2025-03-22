// Write and test a swap function for your valuelike version of HasPtr. Give
// your swap a print statement that notes when it is executed.

#include <iostream>
#include <string>

class HasPtr
{
public:
  friend void swap(HasPtr &a, HasPtr &b);

  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
  HasPtr &operator=(const HasPtr &other);
  ~HasPtr() { delete ps; }

  std::string get_ps() { return *ps; }

private:
  std::string *ps;
  int i;
};

inline void swap(HasPtr &a, HasPtr &b)
{
  std::cout << "swap\n";
  using std::swap;
  swap(a.ps, b.ps);
  swap(a.i, b.i);
}

HasPtr &HasPtr::operator=(const HasPtr &other)
{
  std::cout << "assignment\n";
  auto newp = new std::string(*other.ps);
  delete ps;
  ps = newp;
  i = other.i;
  return *this;
}

int main()
{
  HasPtr hp1("one");
  HasPtr hp2("two");

  std::cout << "hp1: " << hp1.get_ps() << ", hp2: " << hp2.get_ps() << "\n";

  swap(hp1, hp2);

  std::cout << "hp1: " << hp1.get_ps() << ", hp2: " << hp2.get_ps() << "\n";
}