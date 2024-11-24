// Redo the previous exercise, this time using shared_ptr.

#include <iostream>
#include <memory>
#include <vector>

using Vi = std::vector<int>;

std::shared_ptr<Vi> vi_factory() { return std::make_shared<Vi>(); }

void populate(std::shared_ptr<Vi> vi)
{
  int x;
  while (std::cin >> x)
  {
    vi->push_back(x);
  }
}

void print(std::shared_ptr<Vi> vi)
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
}