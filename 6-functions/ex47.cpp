// Revise the program you wrote in the exercises in 6.3.2 that used recursion
// to print the contents of a vector to conditionally print information about
// its execution. For example, you might print the size of the vector on each
// call. Compile and run the program with debugging turned on and again with
// it turned off.

#include <iostream>
#include <vector>
#include <cassert>

using std::cout;
using std::cerr;
using std::vector;

template <typename T>
void print_v(vector<T> v)
{
  #ifndef NDEBUG
  cerr << __func__ << ": vector size is " << v.size() << '\n';
  #endif

  cout << v[0];
  if (v.size() > 1)
  {
    cout << " ";
    vector<T> sub_v(v.begin() + 1, v.end());
    print_v(sub_v);
  }
}

int main()
{
  vector<int> vi = {0, 1, 1, 2, 3, 5, 8};
  vector<char> vc = {'h', 'e', 'l', 'l', 'o'};

  print_v(vi);
  cout << '\n';
  print_v(vc);
}