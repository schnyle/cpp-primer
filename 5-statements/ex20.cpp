// Write a program to read a sequence of strings from the standard input until
// either the same word occurs twice in succession or all the words have been
// read. Use a while loop to read the text one word at a time. Use the break
// statement to terminate the loop if a word occurs twice in succession. Print
// the word if it occurs twice in succession, or else print a message that no
// word was repeated.

#include <iostream>

using namespace std;

int main()
{
  string curr_word, prev_word;
  bool is_repeated = false;
  while (cin >> curr_word)
  {
    if (prev_word == curr_word)
    {
      is_repeated = true;
      break;
    }
    prev_word = curr_word;
  }

  cout << (is_repeated ? "Repetition: " + curr_word : "No repetition.") << endl;

  return 0;
}