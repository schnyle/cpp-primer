// 47 Give the copy constructor and copy-assignment operator in your String
//    class from exercise 13.44 in S13.5 a statement that prints a message each
//    time the function is executed.
//
// 48 Define a vector<String> and call push_back several times on that vector.
//    Run your program and see how often Strings are copied.

#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class String
{
public:
  String() : chars(nullptr), first_free(nullptr), cap(nullptr) {}
  String(const char *);
  String(const String &);
  ~String() { free(); }

  String &operator=(const String &);
  String &operator+=(const char);

  size_t size() const { return first_free - chars; }
  size_t capacity() const { return cap - chars; }
  char *begin() const { return chars; }
  char *end() const { return first_free; }

private:
  char *chars;
  char *first_free;
  char *cap;

  static std::allocator<char> alloc;
  std::pair<char *, char *> alloc_and_copy(const char *, const char *);
  void check_and_alloc();
  void reallocate();
  void free();
};

std::allocator<char> String::alloc;

String::String(const char *s)
{
  const auto l = std::strlen(s);
  auto [b, e] = alloc_and_copy(s, s + l);
  chars = b;
  first_free = cap = e;
}

String::String(const String &rhs)
{
  std::cout << "Calling copy constructor\n";
  auto [b, e] = alloc_and_copy(rhs.begin(), rhs.end());
  chars = b;
  first_free = cap = e;
}

String &String::operator=(const String &rhs)
{
  std::cout << "Calling copy assignment operator\n";
  auto [b, e] = alloc_and_copy(rhs.begin(), rhs.end());
  free();
  chars = b;
  first_free = cap = e;
  return *this;
}

String &String::operator+=(const char c)
{
  check_and_alloc();
  *first_free++ = c;
  return *this;
}

std::pair<char *, char *> String::alloc_and_copy(const char *b, const char *e)
{
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void String::check_and_alloc()
{
  if (size() == capacity())
  {
    reallocate();
  }
}

void String::reallocate()
{
  const size_t new_cap = size() ? 2 * size() : 1;
  auto new_begin = alloc.allocate(new_cap);

  auto dest = new_begin;
  auto source = chars;
  for (size_t i = 0; i < size(); ++i)
  {
    alloc.construct(dest++, *source++);
  }
  free();

  chars = new_begin;
  first_free = dest;
  cap = new_begin + new_cap;
}

void String::free()
{
  std::for_each(chars, first_free, [&](char &x) { alloc.destroy(&x); });
  alloc.deallocate(chars, cap - chars);
}

void print_String(const String &s)
{
  if (!s.begin())
  {
    return;
  }

  for (auto it = s.begin(); it != s.end(); ++it)
  {
    std::cout << *it;
  }
  std::cout << "\n";
}

int main()
{
  std::vector<String> v;
  std::cout << "1\n";
  v.push_back("Hello");
  std::cout << "2\n";
  v.push_back("how");
  std::cout << "3\n";
  v.push_back("are");
  std::cout << "4\n";
  v.push_back("you");
}