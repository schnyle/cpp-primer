#include <fstream>
#include <sstream>

#include "QueryResult.hpp"
#include "TextQuery.hpp"

TextQuery::TextQuery(std::ifstream &is) : lines(new std::vector<std::string>)
{
  std::string text;
  while (std::getline(is, text))
  {
    lines->push_back(text);

    size_t n = lines->size() - 1;
    std::string word;
    std::stringstream iss(text);
    while (iss >> word)
    {
      auto &wordLines = wordMap[word];
      if (!wordLines)
      {
        wordLines.reset(new std::set<LineNum>);
      }
      wordMap[word]->insert(n);
    }
  }
}

QueryResult TextQuery::query(const std::string &word)
{
  static std::shared_ptr<std::set<LineNum>> noData(new std::set<LineNum>);

  auto loc = wordMap.find(word);
  if (loc == wordMap.cend())
  {
    return QueryResult(word, lines, noData);
  }
  return QueryResult(word, lines, loc->second);
}