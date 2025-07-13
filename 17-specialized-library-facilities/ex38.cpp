// Extend your program from the previous exercise to print each word you read
// onto its own line.

#include <cstdio>
#include <cstring>
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

  while (f.getline(sink, size, ' ') || f.gcount())
  {
    // handle consecutive spaces
    if (strlen(sink) == 0)
    {
      continue;
    }

    // handle newline char
    if (sink[strlen(sink) - 1] == '\n')
    {
      sink[strlen(sink) - 1] = '\0';
    }

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