#include <iostream>
#include <string>
#include <array>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
  int mat[4][4];

  for (auto &row : mat)
    for (auto &col : row)
      cout << 0 << endl;

  return 0;
}