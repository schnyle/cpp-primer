#include <stdexcept>

#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"

StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz) : wptr(a.data), curr(sz) {}
StrBlobPtr::StrBlobPtr(const StrBlob &a, size_t sz) : wptr(a.data), curr(sz) {}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
  auto res = wptr.lock();
  if (!res)
  {
    throw std::runtime_error("unbound StrBlobPtr");
  }
  if (i >= res->size())
  {
    throw std::out_of_range(msg);
  }
  return res;
}

std::string &StrBlobPtr::deref() const
{
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr &StrBlobPtr::incr(size_t i)
{
  check(curr + i, "increment past end of StrBlobPtr");
  curr += i;
  return *this;
}
