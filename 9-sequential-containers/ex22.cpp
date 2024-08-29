// Assuming iv is a vector of ints, what is wrong with the following program?
// How might you correct the probelm(s)?

// vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;

// while (iter != mid)
//   if (*iter == some_val)
//     iv.insert(iter, 2 * some_val);

#include <iostream>
#include <vector>

int main()
{
  int some_val = 420;
  std::vector<int> iv{1, 2, 3, 420, 69, 1776, 2024, 1999, 7, 24};

  std::vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;

  while (iter != mid)
  {
    if (*iter == some_val)
    {
      iv.insert(iter, 2 * some_val);
    }
    ++iter;
  }

  for (auto i : iv)
  {
    std::cout << i << " ";
  }
  std::cout << "\n";
}