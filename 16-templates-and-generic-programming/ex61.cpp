// Define your own version of make_shared.

#include <iostream>
#include <memory>
#include <string>

template <typename T, typename... Args>
std::shared_ptr<T> my_make_shared(Args &&...args)
{
  return std::shared_ptr<T>(new T(std::forward<Args>(args)...))
}

class Person
{
public:
  Person(std::string n, int a, bool e) : name(n), age(a), employed(e) {}

private:
  std::string name;
  int age;
  bool employed;
};

int main() { auto x = my_make_shared<Person>("Kyle", 25, true); }