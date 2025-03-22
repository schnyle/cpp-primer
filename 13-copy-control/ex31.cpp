// Give your class a < operator and define a vector of HasPtrs. Give the vector
// some elements and then sort the vector. Note when swap is called.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class HasPtr
{
public:
  friend void swap(HasPtr &a, HasPtr &b);

  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}

  HasPtr &operator=(const HasPtr &other);
  bool operator<(const HasPtr &other) const { return *(this->ps) < *other.ps; };

  ~HasPtr() { delete ps; }

  std::string get_ps() { return *ps; }

private:
  std::string *ps;
  int i;
};

inline void swap(HasPtr &a, HasPtr &b)
{
  std::cout << "swap (" << *a.ps << " with " << *b.ps << ")\n";
  using std::swap;
  swap(a.ps, b.ps);
  swap(a.i, b.i);
}

HasPtr &HasPtr::operator=(const HasPtr &other)
{
  std::cout << "assignment (" << *other.ps << " to " << *(this->ps) << ")\n";
  auto newp = new std::string(*other.ps);
  delete ps;
  ps = newp;
  i = other.i;
  return *this;
}

int main()
{
  HasPtr hp1("z");
  HasPtr hp2("x");
  HasPtr hp3("y");
  HasPtr hp4("b");
  HasPtr hp5("a");

  std::vector<HasPtr> v{hp1, hp2, hp3, hp4, hp5};
  for (size_t i = 0; i < v.size(); ++i)
  {
    for (size_t j = 0; j < v.size() - 1; ++j)
    {
      if (v[j + 1] < v[j])
      {
        // This will directly call your custom swap function
        ::swap(v[j], v[j + 1]);
      }
    }
  }

  // std::sort(v.begin(), v.end(), std::less<HasPtr>());
}