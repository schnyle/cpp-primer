#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  // array
  int av1[] = {1, 2, 3};
  int av2[] = {1, 2, 3, 4};
  int *pav1 = av1;
  int *eav1 = av1 + 3;
  int *pav2 = av2;
  int *eav2 = av2 + 4;
  while (pav1 != eav1 && pav2 != eav2)
  {
    if (*pav1 != *pav2)
    {
      cout << "Not equal.\n";
      break;
    }
    pav1++;
    pav2++;
  }
  if (pav1 != eav1 || pav2 != eav2) 
    cout << "Not equal.\n";
  else
    cout << "Equal.\n";

  return 0;
}