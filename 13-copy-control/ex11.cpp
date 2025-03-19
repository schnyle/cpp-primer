// Add a destructor to your HasPtr class from the previous exercises.

#include <string>

class HasPtr
{
public:
  // constructor
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

  // copy constructor
  HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}

  // copy assignment operator
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

  // destructor
  ~HasPtr() { delete ps; }

private:
  std::string *ps;
  int i;
};