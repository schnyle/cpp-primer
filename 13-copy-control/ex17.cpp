// Write versions of `numbered` and `f` corresponding to the previous three
// exercises and check whether you correctly predicted the output.

#include <iostream>

class numbered
{
public:
  numbered() : mysn(generate_id()) {}
  numbered(const numbered &other) : mysn(generate_id()) {}

  int mysn;

private:
  static int generate_id()
  {
    static int id = 0;
    return id++;
  }
};

void f(const numbered &s) { std::cout << s.mysn << std::endl; }

int main()
{
  numbered a, b = a, c = b;

  f(a);
  f(b);
  f(c);
}

// Without the copy constructor, mysn is always 0 since everything is a copy of
// a. Adding the copy constructor generates a new mysn for each instance. But
// the output is not 0, 1, 2, because the copy constructor is also called in
// f(numbered s). When the arguemnt of f becomes f(const numbered &s), now f is
// printing mysn for the original numbered instance, not a of the instance that
// was passed in.