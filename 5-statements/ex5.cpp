// Using an if-else statement, write your own version of the program to
// generate the letter grade from a numeric grade.

#include <iostream>
#include <vector>

using namespace std;

string get_grade(int score)
{
  string grade;

  if (score == 100)
    grade = "A++";
  else if (score > 89)
    grade = "A";
  else if (score > 79)
    grade = "B";
  else if (score > 69)
    grade = "C";
  else if (score > 59)
    grade = "D";
  else
    grade = "F";
  
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
  vector<int> scores {100, 99, 94, 91, 89, 85, 82, 77, 72, 69, 65, 60, 59, 55, 51, 45, 6};

  for (auto &x : scores)
    cout << x << ": " << get_grade(x) << endl;

  return 0;
}