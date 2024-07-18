// Write a function to swap two int pointers.

#include <iostream>

using namespace std;

void swap(int *&pi1, int *&pi2)
{
  int *temp = pi1;
  pi1 = pi2;
  pi2 = temp;
}

int main ()
{
  int i1 = 4;
  int i2 = 3;

  int *pi1 = &i1;
  int *pi2 = &i2;

  swap(pi1, pi2);

  cout << "pi1: " << *pi1 << " pi2: " << *pi2 << endl;

  return 0;
}