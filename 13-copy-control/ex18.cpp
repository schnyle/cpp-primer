// Define an Employee class that contains an employee name and a unique employee
// identifier. Give the class a default constructor and a constructor that takes
// a string representing the employee's name. Each constructor should generate a
// unique ID by incrementing a static data member.

#include <string>

class Employee
{
public:
  Employee() : id(generate_id()), name("NA") {}
  Employee(const std::string &s) : id(generate_id()), name(s) {}

  int id;
  std::string name;

private:
  static int generate_id()
  {
    static int id = 0;
    return id++;
  }
};