// Rewrite the map that stored vectors of children's names with a key that is
// the family last name for the exercises in S11.2.1 to use a multimap.

#include <iostream>
#include <map>
#include <string>
#include <vector>

using Families = std::multimap<std::string, std::vector<std::string>>;

void create_family(Families &families, const std::string &f_name,
                   const std::vector<std::string> &children = {})
{
  families.insert({f_name, children});
}

int main()
{
  std::multimap<std::string, std::vector<std::string>> families;

  create_family(families, "Kyle", {});
  create_family(families, "Schneider", {"Kyle", "Rebecca"});
  create_family(families, "Schneider", {"Bella"});

  for (auto &f : families)
  {
    std::string f_name{f.first};
    std::cout << "The " << f_name << "s:\n";
    for (auto &c : f.second)
    {
      std::cout << "\t" << c << "\n";
    }
  }
}