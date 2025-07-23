// Write a function that takes a forward_list<string> and two additional string
// arguments. The function should find the first stirng and insert the second
// immediately following the first. If the first string is not found, then insert
// the second string at the end of the list.

#include <iostream>
#include <string>
#include <forward_list>

void foo(std::forward_list<std::string> &fl, const std::string s_find, const std::string s_insert)
{
  auto prev = fl.before_begin();
  auto curr = fl.begin();
  while (curr != fl.end())
  {
    if (*curr == s_find)
    {
      fl.insert_after(curr, s_insert);
      return;
    }
    else
    {
      prev = curr;
      ++curr;
    }
  }

  fl.insert_after(prev, s_insert);
}

void p(std::forward_list<std::string> l)
{
  for (auto &s : l)
  {
    std::cout << s << " ";
  }
  std::cout << "\n";
}

int main()
{
  std::forward_list<std::string> fl {"dog", "log", "frog", "hog"};

  foo(fl, "log", "bog");
  p(fl);

  foo(fl, "tog", "tog");
  p(fl);

}