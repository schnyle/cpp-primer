// Write a constexpr template that returns the size of a given array.

#include <iostream>

template <typename Container, size_t N> size_t size(const Container (&arr)[N])
{
  return N;
}

int main()
{
  int x[] = {1, 2, 3};
  std::cout << size(x) << "\n";
}