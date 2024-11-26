// Write a program that reads a string from the standard input into a
// dynamically allocated character array. Describe how your program handles
// varying size inputs. Test your program by giving it a string of data that is
// longer than the array size you've allocated.

#include <cstring>
#include <iostream>
#include <memory>

int main()
{
  size_t size = 8;
  std::unique_ptr<char[]> up(new char[size]);

  char c;
  size_t i = 0;
  while (std::cin >> c)
  {
    if (i >= size - 1)
    {
      size *= 2;
      auto temp = std::make_unique<char[]>(size);
      std::strcpy(temp.get(), up.get());
      up.reset(temp.release());
    }
    up[i++] = c;
  }
  up[i] = '\0';

  std::cout << up.get() << "\n";
}