// Add the move, set, and display operations to your version of Screen. Test
// your class by executing the following code:
//   Screen myScreen(5, 5, 'X');
//   myScreen.move(4, 0).set('#').display(cout);
//   cout << "\n";
//   myScreen.display(cout);
//   cout << "\n";

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

  Screen &move(pos, pos);
  Screen &set(char);
  Screen &set(pos, pos, char);
  Screen &display(std::ostream &os);

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

inline Screen &Screen::move(pos row, pos col)
{
  cursor = width * row + col;
  return *this;
};

inline Screen &Screen::set(char c)
{
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos row, pos col, char c)
{
  contents[width * row + col] = c;
  return *this;
}

inline Screen &Screen::display(std::ostream &os)
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