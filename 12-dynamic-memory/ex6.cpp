// Write a function that returns a dynamically allocated vector of ints. Pass
// that vector to another function that reads the standard input to give values
// to the elements. Pass the vector to another function to print the values that
// were read. Remember to delete the vector at the appropriate time.

#include <iostream>
#include <vector>

using Vi = std::vector<int>;

Vi *vi_factory() { return new Vi; }

void populate(Vi *vi)
{
  int x;
  while (std::cin >> x)
  {
    vi->push_back(x);
  }
}

void print(Vi *vi)
{
  std::cout << "[";
  for (auto &x : *vi)
  {
    std::cout << x << " ";
  }
  std::cout << "]";
}

int main()
{
  auto vi = vi_factory();
  populate(vi);
  print(vi);
  std::cout << "\n";
  delete vi;
}