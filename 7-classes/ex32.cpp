// Define your own versions of Screen and Window_mgr in which clear is a
// member of Window_mgr and a friend of Screen.

#include <iostream>
#include <string>
#include <vector>

using std::cout;

class Screen;
class Window_mg;

class Screen
{
  friend class Window_mgr;

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

class Window_mgr
{
public:
  using ScreenIndex = std::vector<Screen>::size_type;
  void clear(ScreenIndex i);
  ScreenIndex addScreen(const Screen &);
  void display(ScreenIndex);

private:
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};

inline void Window_mgr::clear(ScreenIndex i)
{
  Screen &s = screens[i];
  s.contents = std::string(s.width * s.height, ' ');
}

inline Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
  screens.push_back(s);
  return screens.size() - 1;
}

inline void Window_mgr::display(ScreenIndex i)
{
  screens[i].display(cout);
}

inline Screen &Screen::move(pos row, pos col)
{
  cursor = width * row + col;
  return *this;
}

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
  Window_mgr wm;
  Screen myScreen(5, 5, 'X');
  Window_mgr::ScreenIndex i = wm.addScreen(myScreen);
  wm.display(i);
  cout << "\n";
  wm.clear(i);
  wm.display(i);
  cout << "\n";
}