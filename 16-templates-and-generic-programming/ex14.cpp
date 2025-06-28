// 14 Write a Screen class template that uses nontype parameters to define the
//    height and width of the Screen.
// 15 Implement input and output operators for your Screen template. Which, if
//    any, friends are necessary in class Screen to make the input and output
//    operators work? Explain why each friend declaration, if any, is neeeded.

#include <iostream>

template <unsigned W, unsigned H> class Screen
{
  template <unsigned U, unsigned V>
  friend std::ostream &operator<<(std::ostream &, const Screen<U, V> &);

public:
  Screen() = default;
};

template <unsigned W, unsigned H>
std::ostream &operator<<(std::ostream &os, const Screen<W, H> &)
{
  os << "width: " << W << ", height: " << H;
  return os;
};

int main()
{
  Screen<4, 5> my_screen;
  std::cout << my_screen << "\n";
}
