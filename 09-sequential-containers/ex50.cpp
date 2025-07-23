// Write a program to process a vector<string> whose elements represent integral
// values. Produce the sum of all the elements in that vector. Change the program
// so that it sums of strings that represent floating-point values.

#include <iostream>
#include <vector>
#include <string>

int int_sum(const std::vector<std::string> &v)
{
  int res = 0;

  for (auto &x : v)
  {
    res += std::stoi(x);
  }

  return res;
}

double float_sum(const std::vector<std::string> &v)
{
  double res = 0;

  for (auto &x : v)
  {
    res += std::stod(x);
  }

  return res;
}

int main()
{
  const std::vector<std::string> vi {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
  const std::vector<std::string> vf {"0.1", "0.2", "0.3", "0.4", "0.5", "0.6", "0.7", "0.8", "0.9", "1.0"};

  std::cout << int_sum(vi) << " " << float_sum(vf) << "\n";
}