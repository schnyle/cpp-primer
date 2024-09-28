// Use stream iterators, sort, and copy to read a sequence of integers from the
// standard input, sort them, and then write them back to the standard output.

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main()
{
  std::istream_iterator<int> in_it(std::cin), eof;
  std::vector<int> vi(in_it, eof);

  std::sort(vi.begin(), vi.end());

  std::ostream_iterator<int> out_it(std::cout, " ");
  std::copy(vi.cbegin(), vi.cend(), out_it);
  std::cout << "\n";
}