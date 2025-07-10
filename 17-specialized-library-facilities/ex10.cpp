// Using the sequence 1, 2, 3, 5, 8, 13, 21, initialize a bitset that has a 1
// bit in each position corresponding to a number in this sequence. Default
// initialize another bitset and write a small program to turn on each of the
// appropriate bits.

#include <bitset>
#include <iostream>

int main()
{
  int seq[] = {1, 2, 3, 5, 8, 13, 21};

  // method 1
  unsigned long long ull = 0;
  for (const int i : seq)
  {
    ull += 1UL << i;
  }
  std::bitset<32> bs1(ull);
  std::cout << bs1 << std::endl;

  // method 2
  std::bitset<32> bs2;
  for (const int i : seq)
  {
    bs2.set(i);
  }
  std::cout << bs2 << std::endl;
}