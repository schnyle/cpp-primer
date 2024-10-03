// Write a program that stores the excluded words in a vector instead of in a
// set. What are the advantages of using set?

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
  std::map<std::string, size_t> word_map;
  std::vector<char> punc({'.', ',', '\'', '\"', '!'});

  std::ifstream in("speech.txt");
  std::string word;
  size_t max_word = 0;
  while (in >> word)
  {
    auto remove_it_begin = std::remove_if(word.begin(), word.end(), [punc](const char c)
                                          { return std::find(punc.cbegin(), punc.cend(), c) != punc.cend(); });
    word.erase(remove_it_begin, word.end());
    std::transform(word.cbegin(), word.cend(), word.begin(), [](char c)
                   { return std::tolower(c); });
    ++word_map[word];
    max_word = std::max(max_word, word.size());
  }

  for (auto &x : word_map)
  {
    size_t gap = (max_word + 1) - x.first.size();
    std::cout << x.first << std::string(gap, ' ') << x.second << "\n";
  }
}