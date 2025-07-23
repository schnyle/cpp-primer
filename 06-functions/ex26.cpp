// Write a program that accepts the options presented in this section.
// Print the values of the arguments passed to main

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int i = 0;
  while (argc-- > 0)
  {
    cout << argv[i] << endl;
    ++i;
  }
}