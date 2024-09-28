// Write a program that takes the names of an input file and two ouput files.
// The input file should hold integers. Using an istream_iterator read the
// input file. Using ostream_iterators, write the odd numbers into the first
// output file. Each value should be followed by a space. Write the even numbers
// into the second file. Each of these values should be placed on a separte line.

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

int main()
{
  std::ifstream in("in.txt");
  std::istream_iterator<int> in_it(in), eof;
  std::vector<int> nums(in_it, eof); // don't necessarily need to use this mem

  std::ofstream odd_out("odd.txt");
  std::ostream_iterator<int> odd_out_it(odd_out, "\n");
  std::copy_if(nums.cbegin(), nums.cend(), odd_out_it, [](int x)
               { return x % 2; });

  std::ofstream even_out("even.txt");
  std::ostream_iterator<int> even_out_it(even_out, "\n");
  std::copy_if(nums.cbegin(), nums.cend(), even_out_it, [](int x)
               { return !(x % 2); });
}