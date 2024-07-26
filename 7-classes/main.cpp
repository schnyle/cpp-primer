#include <iostream>
#include <string>

using std::cout;

typedef std::string T;
T initVal();
class Ex
{
public:
  typedef double T;
  T setVal(T);
  T initVal();
private:
  int val;
};
T Ex::setVal(T param)
{
  val = param + initVal();
  return val;
}

int main()
{
}