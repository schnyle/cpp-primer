// Using the library function objects and adaptors, define an expression to
//   (a) Count the number of values that are greater than 1024
//   (b) Find the first string that is not equal to pooh
//   (c) Multiply all values by 2

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
  // a
  std::vector<int> nums = {500,  1000, 1500, 2000, 800,
                           1200, 3000, 1024, 1025}; // answer =  5
  int count =
      std::count_if(nums.begin(), nums.end(), [](int x) { return x > 1024; });
  std::cout << "count: " << count << "\n";

  // b
  std::vector<std::string> strs = {"pooh", "pooh", "hoop",
                                   "pooh", "pooh", "loop"};
  std::string str =
      *std::find_if(strs.begin(), strs.end(),
                    [](const std::string &s) { return s != "pooh"; });
  std::cout << "string: " << str << "\n";

  // c
  std::vector<double> floats = {3.14, 0.999, 1.2345};
  std::transform(floats.cbegin(), floats.cend(), floats.begin(),
                 [](double f) { return 2 * f; });
  std::cout << "doubled: ";
  for (auto x : floats)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
}