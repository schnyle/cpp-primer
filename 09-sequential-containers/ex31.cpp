// The program on page 354 to remove even-valued elements and duplicate odd
// ones will not work on a list or forward_list. Why? Revise the program so
// that it works on these types as well.

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>

template <typename T>
void foo(T &cont)
{
  auto iter = cont.begin();

  while (iter != cont.end())
  {
    if (*iter % 2)
    {
      iter = cont.insert(iter, *iter);
      std::advance(iter, 2);
    }
    else
    {
      iter = cont.erase(iter);
    }
  }

  for (auto &x : cont)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

void bar(std::forward_list<int> &cont)
{
  auto curr = cont.begin();
  auto prev = cont.before_begin();

  while (curr != cont.end())
  {
    if (*curr % 2)
    {
      curr = cont.insert_after(curr, *curr);
      prev = curr;
      ++curr;
    }
    else
    {
      curr = cont.erase_after(prev);
    }
  }

  for (auto &x : cont)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

int main()
{
  std::vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  foo(li);
  foo(vi);
  bar(fli);
}