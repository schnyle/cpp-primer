// Rewrite the phone number program from this section to read from a file 
// rather than from cin.

#include <iostream>
#include <sstream>
#include <fstream>
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

  std::string input_file_name = "people.txt";
  std::fstream input_file(input_file_name);

  while (getline(input_file, line))
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