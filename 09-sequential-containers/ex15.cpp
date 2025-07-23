// Write a program to determine whether two vector<int>s are equal.

#include <iostream>
#include <vector>

bool compare(std::vector<int> &v1, std::vector<int> &v2)
{
  if (v1.size() != v2.size())
    return false;
  
  for (size_t i = 0; i < v1.size(); ++i)
  {
    if (v1[i] != v2[i])
      return false;
  }
  return true;
}

int main()
{
  std::vector<int> v1 = {1, 2, 3};
  std::vector<int> v2 = {1, 2, 3};
  std::vector<int> v3 = {1, 2};
  std::vector<int> v4 = {1, 2, 4};

  std::cout << compare(v1, v2) << "\n";
  std::cout << compare(v1, v3) << "\n";
  std::cout << compare(v1, v4) << "\n";
}