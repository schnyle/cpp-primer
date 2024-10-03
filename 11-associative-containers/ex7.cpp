// Define a map for which the key is the family's last name and the value is a
// vector of the children's names. write code to add new families and to add
// new children to an existing family/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using Families = std::map<std::string, std::vector<std::string>>;

void create_family(
    Families &families,
    const std::string &f_name,
    const std::vector<std::string> &children = {})
{
  families[f_name] = children;
}

void add_children(
    Families &families,
    const std::string &f_name,
    const std::vector<std::string> &children)
{
  if (families.find(f_name) == families.cend())
  {
    std::cout << f_name << " family does not exist, skipping...\n";
    return;
  }
  families[f_name].insert(families[f_name].end(), children.begin(), children.end());
}

int main()
{
  std::map<std::string, std::vector<std::string>> families;

  create_family(families, "Kyle", {});
  create_family(families, "Schneider", {"Kyle", "Rebecca"});
  create_family(families, "Pearson");
  add_children(families, "Pearson", {"Matthew", "Cassidy", "Drew"});
  add_children(families, "Musk", {"a", "b", "c"});

  for (auto &f : families)
  {
    std::string f_name(f.first);
    std::cout << "The " << f_name << "s:\n";
    for (auto &c : families[f_name])
    {
      std::cout << "\t" << c << "\n";
    }
  }

}