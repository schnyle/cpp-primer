// Define your own version of StrBlobPtr and update your StrBloB class with the
// appropriate friend declaration and begin and end members;

#include <exception>
#include <initializer_list>
#include <iostream>
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
  StrBlobPtr end();

private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il))
{
}

class StrBlobPtr
{
public:
  StrBlobPtr() : curr() {}
  StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  std::string &deref() const;
  StrBlobPtr &incr();

private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

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

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

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

int main()
{
  StrBlob b1;
  {
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
  }

  StrBlobPtr bp = b1.begin();

  std::cout << bp.deref() << "\n";
  bp.incr();
  std::cout << bp.deref() << "\n";

  StrBlobPtr bp2 = b1.end();
  std::cout << bp2.deref() << "\n"; // out_of_range exception
}