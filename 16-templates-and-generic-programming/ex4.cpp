// Write a template that acts like the library find algorithm. The function will
// need two template type parameters, one to represent the function's iterator
// parameters and the other for the type of the value. Use your function to find
// a given value in a vector<int> and in a list<string>.

#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename InputIt, typename T>
InputIt find(InputIt first, InputIt last, T value)
{
  while (first != last)
  {
    if (*first == value)
    {
      return first;
    }

    ++first;
  }

  return last;
}

int main()
{
  std::vector<int> v{1, 1, 2, 3, 5, 8, 13};
  std::list<std::string> l{"my", "name", "is", "Kyle"};

  auto index = find(v.begin(), v.end(), 5) - v.begin();
  std::cout << index << "\n";

  auto index2 = std::distance(l.begin(), find(l.begin(), l.end(), "my"));
  std::cout << index2 << "\n";
}