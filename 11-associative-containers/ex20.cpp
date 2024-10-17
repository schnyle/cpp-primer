// Rewrite the word-counting program from S11.1 to use insert instead of
// subscripting. Which program do you think is easier to write and read?

#include <iostream>
#include <map>
#include <string>

int main()
{
  std::map<std::string, size_t> word_count;
  std::string word;
  while (std::cin >> word)
  {
    // auto insert_res = word_count.insert({word, 1});
    // if (!insert_res.second)
    // {
    //   ++insert_res.first->second;
    // }
    ++word_count.insert({word, 0}).first->second;
  }

  for (const auto &w : word_count)
  {
    std::cout << w.first << " occurs " << w.second << " time(s)\n";
  }
}