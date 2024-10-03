// Define a map that associates words with a list of line numbers on which the
// word might occur.

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <sstream>

int main()
{
  std::map<std::string, size_t> word_count_map;
  std::map<std::string, std::list<size_t>> word_line_num_map;
  std::set<char> punc({'.', ',', '\'', '\"', '!'});

  std::ifstream in("speech.txt");
  std::string line;
  std::string word;
  size_t max_word = 0;
  size_t current_line_num = 0;
  while (getline(in, line))
  {
    ++current_line_num;

    std::istringstream iss(line);
    while (iss >> word)
    {

      auto remove_it_begin = std::remove_if(word.begin(), word.end(), [punc](const char c)
                                            { return punc.find(c) != punc.cend(); });
      word.erase(remove_it_begin, word.end());
      std::transform(word.cbegin(), word.cend(), word.begin(), [](char c)
                     { return std::tolower(c); });

      ++word_count_map[word];
      if (word_line_num_map[word].back() != current_line_num)
      { 
        word_line_num_map[word].push_back(current_line_num);
      }

      max_word = std::max(max_word, word.size());
    }
  }

  for (auto &wc : word_count_map)
  {
    std::string word = wc.first;
    size_t gap = (max_word + 1) - wc.first.size();
    std::cout << word << std::string(gap, ' ') << wc.second << "\t[";
    for (auto &st : word_line_num_map[word])
    {
      std::cout << st << " ";
    }
    std::cout << "]\n";
  }
}