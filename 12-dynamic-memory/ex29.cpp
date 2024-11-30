// We coudl have written the loop to manage the interaction with the user as a
// do while loop. Rewrite the loop to use a do while. Explain which version you
// prefer and why.

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
  std::string s;
  do
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
  } while (true);
}

int main()
{
  std::ifstream inputFile("ex28.cpp");
  runQueries(inputFile);
}
