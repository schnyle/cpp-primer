// Reimplement the program that eliminated duplicate words that we wrote in 
// S10.2.3 to use a list instead of a vector.

#include <iostream>
#include <list>
#include <algorithm>
#include <string>

void elimDups(std::list<std::string> &words)
{
  words.sort();

  words.unique();
}

int main()
{
  std::list<std::string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

  elimDups(words);

  for (auto &w : words)
  {
    std::cout << w << " ";
  }
  std::cout << "\n";
}