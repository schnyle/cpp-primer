// Define your own reference-counted version of HasPtr.

#include <string>

class HasPtr
{
public:
  // default constructor
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0), use(new size_t(1))
  {
  }

  // copy constructor
  HasPtr(const HasPtr &other) : ps(other.ps), i(other.i), use(other.use)
  {
    ++*use;
  }

  // copy assignment operator
  HasPtr &operator=(const HasPtr &other)
  {
    ++*other.use;
    if (--*use == 0)
    {
      delete ps;
      delete use;
    }
    ps = other.ps;
    i = other.i;
    use = other.use;
    return *this;
  }

  // destructor
  ~HasPtr()
  {
    if (--*use == 0)
    {
      delete ps;
      delete use;
    }
  }

private:
  std::string *ps;
  int i;
  size_t *use;
};