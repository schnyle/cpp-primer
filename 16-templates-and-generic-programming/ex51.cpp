// 51 Determine what sizeof...(Args) and sizeof...(rest) return for each call to
// foo in this section. 52 Write a program to check your answer to the previous
// question.

#include <iostream>
#include <string>

template <typename T, typename... Args>
void foo(const T &t, const Args &...rest)
{
  std::cout << "Args: " << sizeof...(Args) << ", rest: " << sizeof...(rest)
            << "\n";
}

int main()
{
  int i = 0;
  double d = 3.14;
  std::string s = "how now brown cow";

  foo(i, s, 42, d);
  foo(s, 42, "hi");
  foo(d, s);
  foo("hi");
}