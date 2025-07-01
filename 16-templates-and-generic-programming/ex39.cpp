// Use an explicit template argument to make it sensible to pass two string
// literals to the original version of compare fromm S16.1.1.

// template <typename T> int compare(const T &v1, const T &v2)
// {
//   if (v1 < v2)
//     return -1;
//   if (v2 < v1)
//     return 1;
//   return 0;
// }

#include <string>

template <typename T> int compare(const T &v1, const T &v2)
{
  if (v1 < v2)
    return -1;
  if (v2 < v1)
    return 1;
  return 0;
}

int main() { compare<std::string>("hi", "bye"); }