#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"
#include <stdexcept>

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) 
    : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const
{
  if (!(i < data->size()))
  {
    throw std::out_of_range(msg);
  }
};

std::string &StrBlob::front()
{
  check(0, "front on empty StrBlob");
  return data->front();
}

const std::string &StrBlob::front() const
{
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string &StrBlob::back()
{
  check(0, "back on empty StrBlob");
  return data->back();
}

const std::string &StrBlob::back() const
{
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back()
{
  check(0, "pop_back on empty StrBlob");
  return data->pop_back();
};

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

const StrBlobPtr StrBlob::begin() const { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

const StrBlobPtr StrBlob::end() const { return StrBlobPtr(*this, data->size()); }