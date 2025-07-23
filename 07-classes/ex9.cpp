// Add operations to read and print Person objects to the code you wrote for
// the exercises in 7.1.2.

#include <iostream>
#include <string>

struct Person
{
  std::string name;
  std::string address;
  std::string getName() const { return name; }
  std::string getAddress() const { return address; }
};

std::ostream &print(std::ostream &os, const Person &x)
{
  os << "{name: " << x.getName() << ", address: " << x.getAddress() << "}";
  return os;
}

std::istream &read(std::istream &is, Person &x)
{
  is >> x.name >> x.address;
  return is;
}

int main()
{
  Person me;
  read(std::cin, me);
  print(std::cout, me);
  std::cout << '\n';
}