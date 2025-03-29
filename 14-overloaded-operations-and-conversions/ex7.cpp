// Define an output operator for your String class you wrote for the exercises
// in S13.5

#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <memory>
#include <utility>
#include <vector>

class String
{
  friend std::ostream &operator<<(std::ostream &, const String &);

public:
  String() : chars(nullptr), first_free(nullptr), cap(nullptr) {}
  String(const char *);
  String(const String &);
  String(String &&) noexcept;
  ~String() { free(); }

  String &operator=(const String &);
  String &operator=(String &&) noexcept;
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

String::String(String &&rhs) noexcept
    : chars(rhs.chars), first_free(rhs.first_free), cap(rhs.cap)
{
  std::cout << "Calling move constructor\n";
  rhs.chars = rhs.first_free = rhs.cap = nullptr;
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

String &String::operator=(String &&rhs) noexcept
{
  std::cout << "Calling move assignment operator";
  if (this != &rhs)
  {
    free();
    chars = rhs.chars;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.chars = nullptr;
    rhs.first_free = nullptr;
    rhs.cap = nullptr;
  }
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

std::ostream &operator<<(std::ostream &os, const String &string)
{
  std::copy(string.begin(), string.end(), std::ostream_iterator<char>(os));
  return os;
}

int main()
{
  String s("hello");
  std::cout << s << "\n";
}