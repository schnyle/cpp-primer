// Define your own versions of the TextQuery and QueryResult classes and execute
// the runQueries function from 12.3.1.

#include <fstream>
#include <iostream>

#include "QueryResult.hpp"
#include "TextQuery.hpp"

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
  const bool plural = qr.lineNums->size() > 1;
  os << qr.word << " occurs " << qr.lineNums->size() << " time"
     << (plural ? "s\n" : "\n");
  for (auto lineNum : *qr.lineNums)
  {
    os << "\t(line " << lineNum + 1 << ") " << *(qr.lines->begin() + lineNum)
       << "\n";
  }
  return os;
}

void runQueries(std::ifstream &infile)
{
  // infile is an ifstream that is the file we want to query
  TextQuery tq(infile);
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
    print(std::cout, tq.query(s)) << std::endl;
    // qr.print(s, std::cout);
  }
}

int main()
{
  const std::string file = "main.cpp";
  std::ifstream inputFile(file);
  runQueries(inputFile);
}