#pragma once

#include <memory>
#include <string>
#include <vector>

class StrBlob;

class StrBlobPtr
{
public:
  StrBlobPtr() : curr() {}
  StrBlobPtr(StrBlob &a, size_t sz = 0);
  StrBlobPtr(const StrBlob &a, size_t sz = 0);
  std::string &deref() const;
  StrBlobPtr &incr();
  StrBlobPtr &incr(size_t i);

private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};