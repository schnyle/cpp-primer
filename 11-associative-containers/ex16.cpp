// Using a map iterator write an expression that assigns a value to an element.

#include <iostream>
#include <map>
#include <string>

int main()
{
  std::map<std::string, int> word_count{{"stan", 0}, {"dan", 0}, {"pan", 0}};

  int val = 3;
  for (auto it = word_count.begin(); it != word_count.end(); ++it)
  {
    it->second = val;
    val *= val;
  }

  for (auto &p : word_count)
  {
    std::cout << p.first << " " << p.second << "\n";
  }
}