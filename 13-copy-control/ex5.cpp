// Given the following sketch of a class, write a copy constructor that copies
// all the members. Your constructor should dynamically allocate a new string
// and copy the object to which ps points, rather than copying ps itself.

#include <string>

class HasPtr
{
public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}

private:
  std::string *ps;
  int i;
};