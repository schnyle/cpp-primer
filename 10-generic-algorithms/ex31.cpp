// Update the program from the previous exercise so that it prints only the 
// unique elements. Your program should use unique_copy.

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
  std::unique_copy(vi.cbegin(), vi.cend(), out_it);
  std::cout << "\n";
}