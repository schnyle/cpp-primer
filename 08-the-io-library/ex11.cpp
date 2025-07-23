// The program in this section defined its istringstream object inside the
// outer while loop. What changes would you need to make if record were defined
// outside that loop? Rewrite the program, moving the definition of record
// outside the while, and see whether you thought of all the changes that
// are needed.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

int main()
{
  std::string line, word;
  std::vector<PersonInfo> people;
  std::istringstream record;


  while (getline(std::cin, line))
  {
    PersonInfo info;
    record.str(line);
    record >> info.name;
    while (record >> word)
    {
      info.phones.push_back(word);
    }
    people.push_back(info);
    record.clear();
  }

  for (const auto &p : people)
  {
    std::cout << p.name << ":\n";
    for (const auto &n : p.phones)
    {
      std::cout << "\t" << n << "\n";
    }
  }
}