#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v(24, 1);
  v.push_back(23);

  std::cout << v.size() << " " << v.capacity() << "\n";

  auto iter = v.begin();
  while (iter != v.end())
  {
    if (*iter % 2)
    {
      iter = v.insert(iter, *iter);
    }
    ++iter;
  }

  for (auto &x : v)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
}