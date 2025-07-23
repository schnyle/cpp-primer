// Write a program to copy elements from a list<int> into two deques. The
// even-valued elements should go into one deque and the odd ones into the other.

#include <iostream>
#include <list>
#include <deque>

int main()
{
  std::list<int> ilist{1, 2, 3, 420, 69, 1776, 2024, 1999, 7, 24};
  std::deque<int> even;
  std::deque<int> odd;

  for (auto i : ilist)
  {
    if (i % 2 == 0)
    {
      even.push_back(i);
    }
    else
    {
      odd.push_back(i);
    }
  }

  std::cout << "even: ";
  for (auto i : even)
  {
    std::cout << i << " ";
  }
  std::cout << "\n";

  std::cout << "odd: ";
  for (auto i : odd)
  {
    std::cout << i << " ";
  }
  std::cout << "\n";
}