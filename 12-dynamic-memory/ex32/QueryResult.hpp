#pragma once

#include <memory>
#include <set>
#include <string>
#include <vector>

#include "StrBlob.hpp"

class QueryResult
{
  friend std::ostream &print(std::ostream &, const QueryResult &);

public:
  using LineNum = std::vector<std::string>::size_type;
  QueryResult(std::string s, StrBlob fb,
              std::shared_ptr<std::set<LineNum>> ln)
      : word(s), fileBlob(fb), lineNums(ln)
  {
  }

private:
  std::string word;
  StrBlob fileBlob;
  std::shared_ptr<std::set<LineNum>> lineNums;
};