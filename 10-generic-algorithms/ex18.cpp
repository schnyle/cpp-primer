// Rewrite biggies to use partition instead of find_if.

#include <iostream>
#include <vector>
#include <algorithm>

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
  // elimDups
  std::sort(words.begin(), words.end());
  auto end_unq = std::unique(words.begin(), words.end());
  words.erase(end_unq, words.end());

  // resort by length, maintaining alphabetical order among words of the same lenght
  std::stable_sort(words.begin(), words.end(), [](const std::string &s1, const std::string &s2)
                   { return s1.size() < s2.size(); });

  // get an iterator to the first element whose size() is >= sz
  auto iter = std::partition(words.begin(), words.end(), [sz](const std::string &s)
                             { return s.size() < sz; });

  // compute the number of elements with size >= sz
  auto numBigWords = std::distance(iter, words.end());

  // print words of the given dize or longer, each one followed by a space
  std::for_each(iter, words.end(), [](const std::string &s)
                { std::cout << s << " "; });
  std::cout << "\n";
}

int main()
{
  std::vector<std::string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

  biggies(words, 4);
}