// Write a template verison of the print function from S6.2.4 that takes a
// reference to an array and can handle arrays of any size and any element type.

// void print(const int ia[], size_t size)
// {
//   for (size_t i = 0; i != size; ++i)
//   {
//     cout << ia[i] << endl;
//   }
// }

#include <iostream>

template <typename T, size_t N> void print(const T (&arr)[N])
{
  for (size_t i = 0; i != N; ++i)
  {
    std::cout << arr[i] << std::endl;
  }
}

int main()
{
  int x[] = {1, 2, 3};
  print(x);
}