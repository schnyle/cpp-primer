#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void print_vector(vector<T> x)
{
  cout << '[';
  for (auto e : x)
    cout << e << ' ';
  cout << "]\n";
}

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    cout << "Specify input types.";
    return -1;
  }

  string itype = argv[1];

  if (itype == "int")
  {
    vector<int> iv;
    int i;
    while (cin >> i)
      iv.push_back(i);
    print_vector(iv);
    return 0;
  }

  if (itype == "str")
  {
    vector<string> sv;
    string s;
    while (cin >> s)
      sv.push_back(s);
    print_vector(sv);
    return 0;
  }

  cout << "Input type not recognized.\n";

  return 0;
}