#pragma once

#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;

class StrBlob
{
  friend class StrBlobPtr;

public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const std::string &s) { data->push_back(s); }
  void pop_back();
  std::string &front();
  const std::string &front() const;
  std::string &back();
  const std::string &back() const;
  StrBlobPtr begin();
  const StrBlobPtr begin() const;
  StrBlobPtr end();
  const StrBlobPtr end() const;

private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};