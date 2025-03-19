// Does your Employee classs need to define its own versions of the copy-control
// members? If so, why? If not, why not? Implement whatever copy-control members
// you think Employee needs.

#include <string>

class Employee
{
public:
  Employee() : id(generate_id()), name("NA") {}
  Employee(const std::string &s) : id(generate_id()), name(s) {}

  Employee(const Employee &other) : id(generate_id()), name(other.name) {}

  Employee &operator=(const Employee &other)
  {
    name = other.name;
    return *this;
  }

  int id;
  std::string name;

private:
  static int generate_id()
  {
    static int id = 0;
    return id++;
  }
};