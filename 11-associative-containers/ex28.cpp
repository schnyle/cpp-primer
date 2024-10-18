// Define and initialize a variable to hold the result of calling find on a map
// from string to vector of int.

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
  std::map<std::string, std::vector<int>> m;

  std::string target("jello");
  std::map<std::string, std::vector<int>>::iterator it = m.find(target);
}