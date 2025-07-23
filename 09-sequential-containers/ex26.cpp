// Using the following definition of ia, copy ia into a vector and into a list.
// Use the single-iterator form of erase to remove the elements with odd values
// from your list and the even values from your vector.

#include <iostream>
#include <vector>
#include <list>

template <typename T>
void p(T c)
{
  for (auto &x : c)
  {
    std::cout << x << "\n";
  }
}

int main()
{
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  size_t s = sizeof(ia) / sizeof(ia[0]);

  std::vector<int> iv;
  iv.insert(iv.end(), ia, ia + s);
  for (auto it = iv.begin(); it != iv.end();)
    if (!*it % 2)
      it = iv.erase(it);
    else
      ++it;

  std::list<int> il;
  il.insert(il.end(), ia, ia + s);
  for (auto it = il.begin(); it != il.end();)
    if (*it % 2)
      it = il.erase(it);
    else
      ++it;

  for (auto &x : iv)
    std::cout << x << " ";
  std::cout << "\n";
  for (auto &x : il)
    std::cout << x << " ";
  std::cout << "\n";
}