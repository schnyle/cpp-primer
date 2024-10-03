// Extend the map of children to their family name that you wrote for the
// exercises in S11.21 by having the vector store a pair that holds a child's
// name and birthday.

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using Child = std::pair<std::string, std::string>;

using Families = std::map<std::string, std::vector<Child>>;

void create_family(
    Families &families,
    const std::string &f_name,
    const std::vector<Child> &children = {})
{
  families[f_name] = children;
}

void add_children(
    Families &families,
    const std::string &f_name,
    const std::vector<Child> &children)
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
  Families families;

  create_family(families, "Kyle", {});
  create_family(families, "Schneider", {{"Kyle", "July 24 1999"}, {"Rebecca", "April 27 1997"}});
  create_family(families, "Pearson");
  add_children(families, "Pearson", {{"Matthew", "Matthew's birthday"}, {"Cassidy", "July 2 1776"}, {"Drew", "yesterday"}});
  add_children(families, "Musk", {{"a", "aa"}, {"b", "bb"}, {"c", "cc"}});

  for (auto &f : families)
  {
    std::string f_name(f.first);
    std::cout << "The " << f_name << "s:\n";
    for (auto &[c_name, c_birthday] : families[f_name])
    {
      std::cout << "\t" << c_name << " -> " << c_birthday << "\n";
    }
  }

}