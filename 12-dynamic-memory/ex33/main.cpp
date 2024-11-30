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
    os << "\t(line " << lineNum + 1 << ") " << *(qr.fileBlob->begin() + lineNum)
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

void testBeginEndMethods(std::ifstream &infile) {
  TextQuery tq(infile);
  auto qr = tq.query("#include");

  std::cout << "begin()/end() test:\n";
  auto beginIt = qr.begin();
  while (beginIt != qr.end())
  {
    std::cout << "\tline: " << 1 + *beginIt++ << "\n";
  }
  std::cout << "\n";
}

void testGetFile(std::ifstream &infile)
{
  TextQuery tq(infile);
  auto qr = tq.query("#include");

  std::cout << "get_file() test:\n";
  auto file = qr.get_file();
  for (int i = 0; i < file->size(); ++i)
  {
    std::cout << "\t" << file->at(i) << "\n";
  }
}

int main()
{
  const std::string file = "main.cpp";
  std::ifstream inputFile(file);
  // runQueries(inputFile)

  // testBeginEndMethods(inputFile);
  
  testGetFile(inputFile);
}