// Write a program to implement text queries without defining classes to manage
// the data. Your program should take a file and interact with a user to query
// for words in that file. Use vector, map, and set containers to hold the data
// for the file and to generate the results for the queries.

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using Lines = std::vector<std::string>;
using WordLines = std::map<std::string, std::set<size_t>>;

std::string query(const std::string &word, const Lines &lines,
                  WordLines &wordLines)
{
  std::stringstream ss;
  ss << word << " occurs " << wordLines[word].size() << " times\n";
  for (auto &i : wordLines.at(word))
  {
    ss << "\t(line " << i + 1 << ") " << lines[i] << "\n";
  }

  return ss.str();
}

std::ostream &print(std::ostream &os, const std::string &s)
{
  os << s;
  return os;
}

void runQueries(std::ifstream &infile)
{
  Lines lines;
  WordLines wordLines;

  std::string line;
  while (std::getline(infile, line))
  {
    lines.push_back(line);
  }

  for (size_t i = 0; i < lines.size(); ++i)
  {
    std::string word;
    std::istringstream iss(lines[i]);
    while (iss >> word)
    {
      wordLines[word].insert(i);
    }
  }

  // iterate with the user: prompt for a word to find and print results
  while (true)
  {
    std::cout << "enter word to look for, or q to quit: ";
    std::string s;
    // stop if we hit end-of-file on the input or if a 'q' is entered
    if (!(std::cin >> s) || s == "q")
    {
      break;
    }
    // run the query and print the results
    print(std::cout, query(s, lines, wordLines)) << std::endl;
  }
}

int main()
{
  std::ifstream inputFile("ex28.cpp");
  runQueries(inputFile);
}
