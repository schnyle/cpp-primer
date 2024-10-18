// Implement your own version of the word-transformation program.

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main()
{
  // create map
  std::ifstream rules("rules.txt");
  std::map<std::string, std::string> word_map;
  std::string key, rules_line;
  while (rules >> key && getline(rules, rules_line))
  {
    word_map[key] = rules_line.substr(1);
  }

  // translate text
  std::ifstream raw_text("text.txt");
  std::string word, text_line;
  while (getline(raw_text, text_line))
  {
    bool first_word = true;
    std::stringstream ss(text_line);
    while (ss >> word)
    {
      auto it = word_map.find(word);
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