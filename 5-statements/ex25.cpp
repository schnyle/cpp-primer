// ex23: Write a program that reads two integers from the standard input and
//       prints the result of dividing the first number by the second.
// ex24: Revise your program to throw an exception if the second number is
//       zero. Test your program with a zero input to see what happens on your
//       system if you don't catch an exception

#include <iostream>

using namespace std;

int main()
{
  int i1, i2;
  while (cin >> i1 >> i2)
  {
    try
    {
      if (i2 == 0)
        throw runtime_error("divisor must be nonzero");
      double res = static_cast<double>(i1) / i2;
      cout << i1 << "/" << i2 << " = " << res << endl;
      break;
    }
    catch (runtime_error err)
    {
      cout << err.what() << "\nTry again? (y or n)" << endl;
      char c;
      cin >> c;
      if (c == 'n')
        break;
      else
        continue;
    }
  }

  return 0;
}