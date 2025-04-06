// Write your own version of a simple desk calculator that can handle binary
// operations.

#include <functional>
#include <iostream>
#include <map>

int main()
{
  std::map<char, std::function<double(double, double)>> binops = {
      {'+', [](double x, double y) { return x + y; }},
      {'-', [](double x, double y) { return x - y; }},
      {'*', [](double x, double y) { return x * y; }},
      {'/', [](double x, double y) { return x / y; }},
  };

  std::cout << binops['+'](10.9, 5.005) << "\n";
  std::cout << binops['-'](10.9, 5.005) << "\n";
  std::cout << binops['*'](10.9, 5.005) << "\n";
  std::cout << binops['/'](10.9, 5.005) << "\n";
}