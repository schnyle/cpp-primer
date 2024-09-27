// Write a program that uses stable_sort and isShorter to sort a vector passed
// to your version of elimDups. Print the vector to verify that your program
// is correct.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool isShorter(const std::string &s1, const std::string &s2)
{
  return s1.size() < s2.size();
}

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

  std::stable_sort(words.begin(), words.end(), isShorter);
  std::cout << "stable sorted: ";
  p(words);
  
  std::cout << "final: ";
  p(words);
}

int main()
{
  std::vector<std::string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

  elimDups(words);

}