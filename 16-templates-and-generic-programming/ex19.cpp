// Write a function that takes a reference to a container and prints the
// elements in that container. Use the container's size_type and size members to
// control the loop that prints the elements.

#include <iostream>
#include <vector>

template <typename Container> void print_container(const Container &container)
{
  using SizeType = typename Container::size_type;
  SizeType size = container.size();

  for (SizeType i = 0; i != size; ++i)
  {
    std::cout << container[i] << "\n";
  }
}

int main()
{
  const std::vector<int> v{1, 2, 3};
  print_container(v);
}