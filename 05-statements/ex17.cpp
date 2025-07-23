// Given two vectors of ints, write a program to determine whether one vector
// is a prefix of the other. For vectors of unequal length, compare the number
// of elements of the smaller vector. For example, given the vectors containing
// 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 7, respectively your program should 
// return true.

#include <iostream>
#include <vector>

using namespace std;

bool is_prefix(vector<int> v1, vector<int> v2)
{
  typedef decltype(v1.size()) size;

  size min_len = (v1.size() < v2.size()) ? v1.size() : v2.size();

  for (size i = 0; i != min_len; i++)
    if (v1[i] != v2[i])
      return false;
  
  return true;
}

int main()
{
  vector<int> v1 {0, 1, 1};
  vector<int> v2 {0, 1, 1, 2, 3, 5, 8};

  if (is_prefix(v1, v2))
    cout << "Is prefix" << endl;
  else
    cout << "Is not prefix" << endl;

  return 0;
}