// 11 Define a data structure that contains an integral object to track
//    responses to a true/false quiz containing 10 questions. What changes, if
//    any, would you need to make in your data structure if the quiz had 100
//    questions?
// 12 Using the data structure from the previous question, write a function that
//    takes a question number and a value to indicate a true/false answer and
//    updates the quiz results accordingly.
// 13 Write an integral object that contains the correct answers for the
//    true/false quiz. Use it to generate grades on the quiz for the data
//    structure from the previous two exercises.

#include <bitset>
#include <iostream>

int main()
{
  constexpr int num_questions = 10;

  std::bitset<num_questions> answers("1001110011");

  std::bitset<num_questions> my_answers;
  my_answers.set(0, true);
  my_answers.set(1, false);
  my_answers.set(2, true);
  my_answers.set(3, true);
  my_answers.set(4, false);
  my_answers.set(5, false);
  my_answers.set(6, false);
  my_answers.set(7, true);
  my_answers.set(8, true);
  my_answers.set(9, true);

  std::bitset<num_questions> correct_mask = ~(answers ^ my_answers);
  std::cout << "you got " << correct_mask.count() << " questions correct.\n";
}
