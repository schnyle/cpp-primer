// Write your own version of the word-counting program.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main()
{
  std::map<std::string, size_t> word_map;

  std::ifstream in("speech.txt");
  std::string word;  
  size_t max_word = 0;
  while (in >> word)
  {
    ++word_map[word];
    max_word = std::max(max_word, word.size());
  }

  for (auto &x : word_map)
  {
    size_t gap = (max_word + 1) - x.first.size();
    std::cout << x.first <<  std::string(gap, ' ') << x.second << "\n";
  }
}