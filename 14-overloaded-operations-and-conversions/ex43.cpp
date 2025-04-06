// Using library function objects, determine whether a given int value is
// divisible by any element in a container of ints.

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
  std::vector<int> divisors = {2, 3, 4, 5, 6, 7, 8, 9};

  int subject = 24;

  std::vector<int> subject_divisors;
  std::copy_if(divisors.cbegin(), divisors.cend(),
               std::back_inserter(subject_divisors),
               [&subject](int d) { return !(subject % d); });
  for (auto &x : divisors)
  {
    std::cout << x << ": ";
    if (std::find(subject_divisors.cbegin(), subject_divisors.cend(), x) !=
        subject_divisors.cend())
    {
      std::cout << "yes";
    }
    else
    {
      std::cout << "no";
    }
    std::cout << "\n";
  }
}