// ex23: Write your own version of the Screen class.
// ex24: Give your Screen class three constructors: a default constructor, a
//       constructor that takes values for height and width and initializes the
//       contents to hold the given number of blanks; and a constructor that
//       takes values for height, width, and a character to use as the contents
//       of the screen.

#include <string>

class Screen
{
public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}
  Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {}

private:
  pos height = 0;
  pos width = 0;
  pos cursor = 0;
  std::string contents;
};