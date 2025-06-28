// How do you think the library begin and end functions that take an array
// argument work? Define your own versions of these functions.

#include <cstddef>

template <typename Container, size_t N> Container *begin(Container (&arr)[N])
{
  return arr;
}

template <typename Container, size_t N> Container *end(Container (&arr)[N])
{
  return arr + N;
}
