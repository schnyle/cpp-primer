// Assume that we want HasPtr to behave like a value. That is, each object
// should have its own copy of the string to which the objects point. We'll show
// the definitions of the copy-control members in the next section. However, you
// already know everything you need to know to implement these members. Write
// the HasPtr copy constructor and copy-assignment operator before reading on.

#include <string>

class HasPtr
{
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
  HasPtr &operator=(const HasPtr &other);
  ~HasPtr() { delete ps; }

private:
  std::string *ps;
  int i;
};

HasPtr &HasPtr::operator=(const HasPtr &other)
{
  auto newp = new std::string(*other.ps);
  delete ps;
  ps = newp;
  i = other.i;
  return *this;
}