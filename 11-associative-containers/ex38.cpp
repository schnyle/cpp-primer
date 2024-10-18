// rewrite the word-counting and word-transformation programs to use an
// unordered_map.

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

void word_count()
{
  std::fstream in("speech.txt");
  std::unordered_map<std::string, size_t> word_count;
  std::string word;
  while (in >> word)
  {
    ++word_count[word];
  }

  for (const auto &w : word_count)
  {
    std::cout << w.first << " occurs " << w.second
              << ((w.second > 1) ? " times" : " time") << "\n";
  }
}

void word_transform()
{
  std::ifstream rules("rules.txt");
  std::unordered_map<std::string, std::string> word_map;
  std::string key, rules_line;
  while (rules >> key && getline(rules, rules_line))
  {
    word_map[key] = rules_line.substr(1);
  }

  std::ifstream raw_text("text.txt");
  std::string word, text_line;
  while (getline(raw_text, text_line))
  {
    bool first_word = true;
    std::stringstream ss(text_line);
    while(ss >> word)
    {
      const auto it = word_map.find(word);
      if (it != word_map.cend())
      {
        word = it->second;
      }
      if (!first_word)
      {
        std::cout << " ";
      }
      else
      {
        first_word = false;
      }
      std::cout << word;
    }
    std::cout << "\n";
  }
}

int main() {
  word_count();
  std::cout << "=================================\n";
  word_transform();
}