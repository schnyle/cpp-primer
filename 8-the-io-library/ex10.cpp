// Write a program to store each line from a file in a vector<string>.
// Now use an istringstream to read each element from the vector
// a word at a time.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
  std::string input_file_name = "ex10.cpp";
  std::string line, word;
  std::ifstream file(input_file_name);
  std::vector<std::string> res;
  
  while (getline(file, line))
  {
    res.push_back(line);
  }

  for (auto &l : res)
  {
    std::istringstream ss(l);
    while (ss >> word)
    {
      std::cout << word << '\n';
    }
    std::cout << "NEWLINE\n";
  }

}

