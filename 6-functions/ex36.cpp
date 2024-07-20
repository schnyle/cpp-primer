// ex36: Write the declaration for a functon that returns a reference to an
//       array of ten strings, without using either a trailing return,
//       decltype, or a type alias.
// ex37: Write three additional declarations for the function in the previous
//       exercise. One should use a type alias, one should use a trailing
//       return, and the third should use decltype. Which form do you prefer
//       and why?

#include <iostream>
#include <string>

using namespace std;

string (&f0())[10]
{
  /* ... */
};

using str_arr = string[10];
str_arr& f1()
{
  /* ... */
}

auto f2() -> string(&)[10]
{
  /* ... */
}

string sa[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
decltype(sa)& f3()
{
  /* ... */
}

int main()
{
  // f2 with the trailing return seems like the most elegant and cleanest form
}