// Write your own version of elimDups. Test your program by printing the vector
// after you read the input, after the call to unique, and after the call to
// erase.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void p(std::vector<std::string> &words)
{
  std::cout << "[";
  for (auto &w : words)
  {
    std::cout << w << " ";
  }
  std::cout << "]\n";
}

void elimDups(std::vector<std::string> &words)
{
  std::cout << "orig: ";
  p(words);

  std::sort(words.begin(), words.end());
  std::cout << "sorted: ";
  p(words);

  auto end_unq = std::unique(words.begin(), words.end());
  std::cout << "unqiue: ";
  p(words);

  words.erase(end_unq, words.end());
  std::cout << "erase: ";
  p(words);
}

int main()
{
  std::vector<std::string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

  elimDups(words);
}