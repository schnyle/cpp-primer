#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class StrVec
{
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const std::initializer_list<std::string> &);
  StrVec(const StrVec &);
  StrVec(StrVec &&) noexcept;
  StrVec &operator=(const StrVec &);
  StrVec &operator=(StrVec &&) noexcept;
  ~StrVec() { free(); }

  void push_back(const std::string &);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }

  void print();

private:
  std::string *elements;
  std::string *first_free;
  std::string *cap;

  static std::allocator<std::string> alloc;
  void chk_n_alloc();
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void reallocate();
  void free();
};

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const std::initializer_list<std::string> &il)
{
  auto data = alloc_n_copy(il.begin(), il.end());
  elements = data.first;
  first_free = cap = data.second;
};

StrVec::StrVec(const StrVec &other)
{
  auto newdata = alloc_n_copy(other.begin(), other.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
};

StrVec::StrVec(StrVec &&other) noexcept
    : elements(other.elements), first_free(other.first_free), cap(other.cap)
{
  other.elements = other.first_free = other.cap = nullptr;
}

StrVec &StrVec::operator=(const StrVec &other)
{
  auto newdata = alloc_n_copy(other.begin(), other.end());
  free();
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
};

StrVec &StrVec::operator=(StrVec &&other) noexcept
{
  if (this != &other)
  {
    free();
    elements = other.elements;
    first_free = other.first_free;
    cap = other.cap;
    other.elements = other.first_free = other.cap = nullptr;
  }
  return *this;
}

void StrVec::push_back(const std::string &s)
{
  chk_n_alloc();
  alloc.construct(first_free++, s);
};

void StrVec::print()
{
  auto p = elements;
  std::cout << "[";
  for (int i = 0; i < size(); ++i)
  {
    std::cout << *p++ << " ";
  }
  std::cout << "] " << "size: " << size() << ", cap: " << capacity() << "\n";
}

void StrVec::chk_n_alloc()
{
  if (size() == capacity())
  {
    reallocate();
  }
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::reallocate()
{
  auto newcapacity = size() ? 2 * size() : 1;
  auto newdata = alloc.allocate(newcapacity);

  auto dest = newdata;
  auto source = elements;
  for (size_t i = 0; i < size(); ++i)
  {
    alloc.construct(dest++, std::move(*source++));
  }
  free();

  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}

void StrVec::free()
{
  std::for_each(elements, first_free,
                [&](std::string &x) { alloc.destroy(&x); });
  alloc.deallocate(elements, cap - elements);
}

int main()
{
  StrVec v({"what's", "your", "problem"});
  v.print();

  StrVec u({"new", "vec"});

  v = u;

  v.print();
}