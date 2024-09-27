// Write a function that takes a string and returns a bool indicating whether
// the string has five characters or more. Use that function to partition words.
// Print the elements that have five or more characters. (use std::partition)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isLong(std::string s)
{
  return s.size() >= 5;
}

int main()
{
  std::vector<std::string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle", "masochist", "demonization", "hello"};

  auto shortBegin = std::partition(words.begin(), words.end(), isLong);

  for (auto iter = words.cbegin(); iter != shortBegin; ++iter)
  {
    std::cout << *iter << "\n";
  }
}