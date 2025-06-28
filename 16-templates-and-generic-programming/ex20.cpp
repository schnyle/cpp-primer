// Rewrite the function from the previous exercise to use iterators returned
// from begin and end to control the loop.

#include <iostream>
#include <vector>

template <typename Iterable> void print_container(const Iterable &iterable)
{
  using It = typename Iterable::const_iterator;
  for (It it = iterable.cbegin(); it != iterable.cend(); ++it)
  {
    std::cout << *it << "\n";
  }
}

int main()
{
  const std::vector<int> v{1, 2, 3};
  print_container(v);
}