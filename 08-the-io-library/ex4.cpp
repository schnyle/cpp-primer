// Write a function to open a file for input and read its contents into a vector of
// strings, storing each line as a separate element in the vector.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
  std::string input_file_name = "ex4.cpp";
  std::string line;
  std::ifstream file(input_file_name);
  std::vector<std::string> res;
  
  while (getline(file, line))
  {
    res.push_back(line);
  }

  for (auto &l : res)
  {
    std::cout << l << '\n';
  }
}

