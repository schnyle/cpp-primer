// Define a list that holds elements that are deques that hold ints.

#include <iostream>
#include <list>
#include <deque>

int main()
{
  std::list<std::deque<int>> x;

  for (int i = 0; i < 5; ++i)
  {
    std::deque<int> temp; 
    for (int j = 0; j < 4; ++j)
    {
      temp.push_back(j + i);
    }
    x.push_back(temp);
  }

  for (auto &dq : x)
  {
    for (auto &i : dq)
    {
      std::cout << i << " ";
    }
    std::cout << "\n";
  }
}