// Given a map<string, vector<int>>, write the types used as an argument and as
// the return value for the version of insert that inserts one element.

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

int main()
{
  std::map<std::string, std::vector<int>> m;
  std::pair<std::map<std::string, std::vector<int>>::iterator, bool> res = m.insert(std::pair<std::string, std::vector<int>>({"hi", {1, 2, 3}}));
}