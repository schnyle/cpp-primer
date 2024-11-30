// The TextQuery and QueryResult classes use only capabailities that we have
// already covered. Without looking ahead, write your own versions of these
// classes.

#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class TextQuery;
class QueryResult;

using Lines = std::vector<std::string>;
using WordLines = std::map<std::string, std::set<size_t>>;

class QueryResult
{
public:
  QueryResult() = default;
  QueryResult(TextQuery &tq);

  std::string print(const std::string &word);

private:
  std::shared_ptr<Lines> lines;
  std::shared_ptr<WordLines> wordLines;
};


class TextQuery
{
  friend QueryResult;

public:
  TextQuery() = delete;
  TextQuery(std::ifstream &inFile);

  std::string query(const std::string &word);

private:
  std::shared_ptr<Lines> lines;
  std::shared_ptr<WordLines> wordLines;
  QueryResult queryResult;

  void initializeLines(std::ifstream &inFile);

  void initializeWordLines();

  std::string trimWhitespace(std::string &s);
};

QueryResult::QueryResult(TextQuery &tq)
    : lines(tq.lines), wordLines(tq.wordLines)
{
}

std::string QueryResult::print(const std::string &word)
{
  std::stringstream ss;
  ss << word << " occurs " << (*wordLines)[word].size() << " times\n";
  for (auto &i : (*wordLines)[word])
  {
    ss << "\t(line " << i + 1 << ") " << (*lines)[i] << "\n";
  }

  return ss.str();
}

TextQuery::TextQuery(std::ifstream &inFile)
    : lines(std::make_shared<Lines>()), wordLines(std::make_shared<WordLines>())
{
  initializeLines(inFile);
  initializeWordLines();
  queryResult = QueryResult(*this);
}

std::string TextQuery::query(const std::string &word)
{
  return queryResult.print(word);
}

void TextQuery::initializeLines(std::ifstream &inFile)
{
  std::string l;
  while (std::getline(inFile, l))
  {
    lines->push_back(trimWhitespace(l));
  }
}

void TextQuery::initializeWordLines()
{
  for (size_t i = 0; i < lines->size(); ++i)
  {
    std::string word;
    std::istringstream iss((*lines)[i]);
    while (iss >> word)
    {
      (*wordLines)[word].insert(i);
    }
  }
}

std::string TextQuery::trimWhitespace(std::string &s)
{
  auto it = std::find_if(s.cbegin(), s.cend(),
                         [](char c) { return !std::isspace(c); });
  return std::string(it, s.cend());
};

std::ostream &print(std::ostream &os, const std::string &s)
{
  os << s;
  return os;
}

void runQueries(std::ifstream &infile)
{
  // infile is an ifstream that is the file we want to query
  TextQuery tq(infile);
  QueryResult qr(tq);
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
  std::ifstream inFile("ex27.cpp");
  runQueries(inFile);
}