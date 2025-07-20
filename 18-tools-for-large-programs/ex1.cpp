// What is the type of the exception object in the following throws?
// (a)  range_error r("error");
//      throw r;
// (b)  exception *p = &r;
//      throw *p;
// What would happend if the throw in (b) were written as throw p?

#include <iostream>
#include <stdexcept>

int main()
{
  try
  {
    std::range_error r("error");
    std::exception *p = &r;

    // throw r;
    // throw *p;
    throw p;
  }
  catch (std::range_error)
  {
    printf("range error\n");
  }
  catch (std::exception)
  {
    printf("exception\n");
  }
  catch (std::exception *)
  {
    printf("exception *\n");
  }
}
