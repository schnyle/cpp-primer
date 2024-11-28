// Rewrite the program on page 481 using an allocater.

#include <iostream>
#include <memory>
#include <string>

int main()
{
  const size_t n = 32;
  std::allocator<std::string> alloc;
  
  std::string *const p = alloc.allocate(n);
  std::string *q = p;
  std::string s;
  while (std::cin >> s && q != p + n)
  {
    alloc.construct(q++, s);
  }

  const size_t size = q - p;
  for (int i = 0; i < size; ++i)
  {
    std::cout << *(p + i) << "\n";
  }

  while (q != p)
  {
    alloc.destroy(--q);
  }

  alloc.deallocate(p, size);
}