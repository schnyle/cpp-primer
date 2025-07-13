// Use the unformatted version of getline to read a file a line at a time. Test
// your program by giving it a file that contains empty lines as well as lines
// that are longer than the character array that you pass to getline.

#include <cstdio>
#include <fstream>
#include <iostream>

int main()
{
  std::ifstream f("ex37.cpp");
  if (!f)
  {
    std::cout << "error opening file\n";
    return 1;
  }

  constexpr std::streamsize size = 64;
  char sink[size];

  while (f.getline(sink, size, '\n') || f.gcount())
  {
    std::cout << sink;

    // handle line longer than `size`
    if (f.gcount() == size - 1)
    {
      f.clear();
      continue;
    }

    std::cout << "\n";
  }
}