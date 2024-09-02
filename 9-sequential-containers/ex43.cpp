// Write a function that takes three strings, s, oldVal, and newVal. Using
// iterators, and the insert and erase functions replace all instances of oldVal
// that appear in s by newVal. Test your function by using it to replace common
// abbreviations, such as "tho" by "though" and "thru" by "through".

#include <iostream>
#include <string>

using std::string;

string &foo(string &s, const string old_val, const string new_val)
{
  const auto old_val_size = old_val.size();
  const auto new_val_size = new_val.size();

  auto it = s.begin();
  while (it != s.end())
  {
    const string word(it, it + old_val_size);
    if (word == old_val)
    {
      const auto start = std::distance(s.begin(), it);
      s.erase(start, old_val_size);
      s.insert(start, new_val);
      it += new_val_size;
    }
    else
    {
      ++it;
    };
  }

  return s;
};

int main()
{
  string s = "My dog ran thru the fence, tho I don't know why.";
  foo(s, "thru", "through");
  foo(s, "tho", "though");
  std::cout << s << "\n";
}