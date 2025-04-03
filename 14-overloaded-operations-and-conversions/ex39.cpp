// Revise the previous program to report the count of words that are sizes 1
// through 9 and 10 or more

#include <fstream>
#include <iostream>
#include <string>

class StringLength
{
public:
  StringLength(const size_t n) : sz(n) {}

  bool operator()(const std::string &s) { return s.size() == sz; }

private:
  size_t sz;
};

int main()
{
  int count_less_than_ten = 0;
  int count_ten_or_more = 0;
  std::ifstream ifs("ex39.cpp");

  std::string w;
  while (ifs >> w)
  {
    bool found = false;
    for (int i = 1; i <= 10; ++i)
    {
      if (StringLength(i)(w))
      {
        ++count_less_than_ten;
        found = true;
        break;
      }
    }
    if (!found)
    {
      ++count_ten_or_more;
    }
  }

  std::cout << "count <9: " << count_less_than_ten
            << ", count >=10: " << count_ten_or_more << "\n";
}