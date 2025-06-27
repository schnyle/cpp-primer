// How do you think the library begin and end functions that take an array
// argument work? Define your own versions of these functions.

#include <cstddef>

template <typename T, size_t N> T *begin(T (&arr)[N]) { return arr; }

template <typename T, size_t N> T *end(T (&arr)[N]) { return arr + N; }
