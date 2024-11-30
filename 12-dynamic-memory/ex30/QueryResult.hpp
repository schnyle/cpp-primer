#pragma once

#include <memory>
#include <set>
#include <string>
#include <vector>

class QueryResult
{
  friend std::ostream &print(std::ostream &, const QueryResult &);

public:
  using LineNum = std::vector<std::string>::size_type;
  QueryResult(std::string s, std::shared_ptr<std::vector<std::string>> ls,
              std::shared_ptr<std::set<LineNum>> ln)
      : word(s), lines(ls), lineNums(ln)
  {
  }

private:
  std::string word;
  std::shared_ptr<std::vector<std::string>> lines;
  std::shared_ptr<std::set<LineNum>> lineNums;
};