#pragma once

#include <iterator>
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
      : word(s), fileBlob(ls), lineNums(ln)
  {
  }

  std::set<LineNum>::iterator begin() { return lineNums->begin(); }

  std::set<LineNum>::iterator end() { return lineNums->end(); }

  std::shared_ptr<std::vector<std::string>> get_file() { return fileBlob; }

private:
  std::string word;
  std::shared_ptr<std::vector<std::string>> fileBlob;
  std::shared_ptr<std::set<LineNum>> lineNums;
};