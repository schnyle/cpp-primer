// 2 Write and test your own versions of the compare functions.
// 3 Call your compare function on two Sales_data objects to see how your
//   compiler handles errors during instantiation.

#include <iostream>

struct Sales_data
{
};

template <typename Container>
int compare(const Container &a, const Container &b)
{
  if (a < b)
  {
    return -1;
  }
  if (b < a)
  {
    return 1;
  }
  return 0;
}

int main()
{
  std::cout << compare<int>(1, 2) << "\n";
  std::cout << compare<char>('z', 'f') << "\n";
  std::cout << compare<std::string>("hello", "goodbye") << "\n";

  std::cout << compare<Sales_data>(Sales_data(), Sales_data()) << "\n";
}