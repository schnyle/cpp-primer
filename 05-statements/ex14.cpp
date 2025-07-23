// Write a program to read strings from standard input looking for duplicated
// words. The program should find places in the input where one word is
// followed immediately by itself. Keep track of the largest number of times a
// single repetition occurs and which word is repeated. Print the maximum
// of duplicates, or else print a message saying that no word was repeated.
// For example, if the input is
//    how now now now brown cow cow
// the output should indicate that the word now occured three times.

#include <iostream>

using namespace std;

int main()
{
  string word, prev_word, max_repeat_word;
  unsigned max_repeat_count = 1, curr_repeat_count = 1;
  while (cin >> word)
  {
    if (prev_word == word)
    {
      ++curr_repeat_count;
    }
    else
    {
      if (curr_repeat_count > max_repeat_count)
      {
        max_repeat_count = curr_repeat_count;
        max_repeat_word = prev_word;
      }
      curr_repeat_count = 1;
    }

    prev_word = word;
  }

  if (max_repeat_count > 1)
  {
    cout << max_repeat_word << " repeated " << max_repeat_count << " times" << endl;
  }
  else
  {
    cout << "no repetitions" << endl;
  }

  return 0;
}