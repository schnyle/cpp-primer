#include <fstream>
#include <sstream>

#include "QueryResult.hpp"
#include "TextQuery.hpp"
#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"

TextQuery::TextQuery(std::ifstream &is) : fileBlob()
{
  std::string text;
  while (std::getline(is, text))
  {
    fileBlob.push_back(text);

    size_t n = fileBlob.size() - 1;
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
    return QueryResult(word, fileBlob, noData);
  }
  return QueryResult(word, fileBlob, loc->second);
}