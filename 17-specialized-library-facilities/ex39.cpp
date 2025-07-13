// Write  your own verison of the seek program presented in this section.

// Assumes there is a newline character at end of file

#include <fstream>
#include <iostream>

int main()
{
  std::fstream f("copyOut");
  if (!f)
  {
    std::cout << "error opening file\n";
    return 1;
  }

  char c;
  while (f.get(c) || f.gcount())
  {
    if (c == '\n')
    {
      auto original_position = f.tellg();
      f.seekp(0, std::fstream::end);
      f << original_position << ' ';
      f.seekg(original_position);
    }
  }
  f << '\n';
}