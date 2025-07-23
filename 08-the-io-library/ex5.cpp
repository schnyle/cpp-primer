// Rewrite the previous program to store each word in a separate element.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
  std::string input_file_name = "ex5.cpp";
  std::string word;
  std::ifstream file(input_file_name);
  std::vector<std::string> res;
  
  while (file >> word)
  {
    res.push_back(word);
  }

  for (auto &l : res)
  {
    std::cout << l << '\n';
  }
}

