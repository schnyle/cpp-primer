#include <iostream>

using namespace std;

void foo(const string &s)
{}

double calc(double);

int main()
{
  foo("hello");  

  calc(3);

  return 0;
}