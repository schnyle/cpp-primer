// 2. Explain what happens if an exception occurs at the indicated point:
//    void exercise(int *b, int *e)
//    {
//      std::vector<int> v(b, e);
//      int *p = new int[v.size()];
//      std::ifstream in("ints");
//      // exception occurs here
//    }
// 3. There are two ways to make the previous vode work correctly if an
//    exception is thrown. Describe them and implement them.

// One fix would wrap the potentially throwing code in a try catch block, making
// sure to free the int * before the functions exits. The better way would be to
// just use a std::unique_ptr<int> instead of a int *.

#include <fstream>
#include <stdexcept>
#include <vector>

void exercise(int *b, int *e)
{
  std::vector<int> v(b, e);
  int *p = new int[v.size()];
  std::ifstream in("ints");
  // exception occurs here
  throw std::runtime_error("");
}

int main()
{
  int v[5] = {9, 2, 5, 3, 7};

  exercise(v, v + 5);
}