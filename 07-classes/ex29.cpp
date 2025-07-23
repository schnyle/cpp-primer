// ex28: What would happen in the previous exercise if the return type of move,
//       set, and display was Screen rather than Screen&?
//         -> second display() call will be original Screen
// ex29: Revise your Screen class so that move, set, and display functions
//       return Screen and check your prediction from the previous exercise.

#include <iostream>
#include <string>

using std::cout;

class Screen
{
public:
  typedef std::string::size_type pos;

  Screen() = default;
  Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}
  Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {}

  Screen move(pos, pos);
  Screen set(char);
  Screen set(pos, pos, char);
  Screen display(std::ostream &os);

private:
  void do_display(std::ostream &os)
  {
    for (int i = 0; i != height * width; i++)
    {
      os << contents[i];
      if ((i + 1) % width == 0)
        cout << '\n';
    }
  }

  pos height = 0;
  pos width = 0;
  pos cursor = 0;
  std::string contents;
};

inline Screen Screen::move(pos row, pos col)
{
  cursor = width * row + col;
  return *this;
};

inline Screen Screen::set(char c)
{
  contents[cursor] = c;
  return *this;
}

inline Screen Screen::set(pos row, pos col, char c)
{
  contents[width * row + col] = c;
  return *this;
}

inline Screen Screen::display(std::ostream &os)
{
  do_display(os);
  return *this;
}

int main()
{
  Screen myScreen(5, 5, 'X');
  myScreen.move(4, 0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout);
  cout << "\n";
}