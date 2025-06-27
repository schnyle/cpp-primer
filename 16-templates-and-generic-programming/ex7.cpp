// Write a constexpr template that returns the size of a given array.

#include <iostream>

template <typename T, size_t N> size_t size(const T (&arr)[N]) { return N; }

int main()
{
  int x[] = {1, 2, 3};
  std::cout << size(x) << "\n";
}