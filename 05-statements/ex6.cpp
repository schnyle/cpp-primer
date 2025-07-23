// Rewrite your grading program to use the conditional operator in place of the
// if-else statement.

#include <iostream>
#include <vector>

using namespace std;

string get_grade(int score)
{
  // beautiful!!
  string grade = (score == 100) ? "A++" : (score > 89) ? "A"
                                      : (score > 79)   ? "B"
                                      : (score > 69)   ? "C"
                                      : (score > 59)   ? "D"
                                                       : "F";

  if (grade == "A++" || grade == "F")
    return grade;

  if (score % 10 > 7)
    grade += "+";
  if (score % 10 < 3)
    grade += "-";

  return grade;
}

int main()
{
  vector<int> scores{100, 99, 94, 91, 89, 85, 82, 77, 72, 69, 65, 60, 59, 55, 51, 45, 6};

  for (auto &x : scores)
    cout << x << ": " << get_grade(x) << endl;

  return 0;
}