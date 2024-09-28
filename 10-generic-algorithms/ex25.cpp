// In the exercises for S10.3.2 you wrote a version of biggies that uses
// partition. Rewrite that function to use check_size and bind.

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std::placeholders;

bool check_size(const std::string &s, std::string::size_type sz)
{
  return s.size() < sz;
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
  // elimDups
  std::sort(words.begin(), words.end());
  auto end_unq = std::unique(words.begin(), words.end());
  words.erase(end_unq, words.end());

  // resort by length, maintaining alphabetical order among words of the same lenght
  std::stable_sort(words.begin(), words.end(), [](const std::string &s1, const std::string &s2)
                   { return s1.size() < s2.size(); });

  // auto check_size_s = std::bind(check_size, s, _1);

  // get an iterator to the first element whose size() is >= sz
  auto iter = std::stable_partition(words.begin(), words.end(), std::bind(check_size, _1, sz));

  // compute the number of elements with size >= sz
  auto numBigWords = std::distance(iter, words.end());
  std::cout << "num big words: " << numBigWords << "\n";

  // print words of the given size or longer, each one followed by a space
  std::for_each(iter, words.end(), [](const std::string &s)
                { std::cout << s << " "; });
  std::cout << "\n";
}

int main()
{
  std::vector<std::string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

  biggies(words, 4);
}