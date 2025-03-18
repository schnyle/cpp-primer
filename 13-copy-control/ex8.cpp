// Write the assignment operator for the HasPtr class from exercise 13.5 in
// S 13.1.1. As with the copy constructor, your assignment operator should copy
// the object to which ps points.

#include <string>

class HasPtr
{
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}

  HasPtr &operator=(const HasPtr &rhs)
  {
    if (ps != nullptr)
    {
      *ps = *rhs.ps;
    }
    else
    {
      ps = new std::string(*rhs.ps);
    }

    i = rhs.i;

    return *this;
  }

private:
  std::string *ps;
  int i;
};