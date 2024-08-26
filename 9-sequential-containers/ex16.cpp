// Repeat the previous program, but compare the elements in a list<int>
// to a vector<int>.

#include <iostream>
#include <vector>
#include <list>

bool compare(std::list<int> &l, std::vector<int> &v)
{
  if (l.size() != v.size())
    return false;

  auto l_it = l.begin();
  for (size_t i = 0; i < v.size(); ++i)
  {
    if (*l_it++ != v[i])
      return false;
  }  
  return true;
}

int main()
{
  std::list<int> v1 = {1, 2, 3};
  std::vector<int> v2 = {1, 2, 3};
  std::vector<int> v3 = {1, 2};
  std::vector<int> v4 = {1, 2, 4};

  std::cout << compare(v1, v2) << "\n";
  std::cout << compare(v1, v3) << "\n";
  std::cout << compare(v1, v4) << "\n";
}