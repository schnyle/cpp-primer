#pragma once

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "QueryResult.hpp"

class TextQuery
{
public:
  using LineNum = std::vector<std::string>::size_type;
  TextQuery(std::ifstream &is);
  QueryResult query(const std::string &word);

private:
  std::shared_ptr<std::vector<std::string>> lines;
  std::map<std::string, std::shared_ptr<std::set<LineNum>>> wordMap;
};