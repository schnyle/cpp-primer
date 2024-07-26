// Update your Person class to hide its implementation.

#include <iostream>
#include <string>

class Person;
std::istream &read(std::istream &, Person &);

class Person
{
  friend std::ostream &print(std::ostream &, const Person &);
  friend std::istream &read(std::istream &, Person &);

public:
  Person() = default;
  Person(const std::string &name, const std::string &addr)
      : name(name), address(addr) {}
  Person(std::istream &is) { read(is, *this); }
  std::string getName() const { return name; }
  std::string getAddress() const { return address; }

private:
  std::string name;
  std::string address;
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
  Person who;
  print(std::cout, who) << '\n';

  Person me("Kyle", "Denver");
  print(std::cout, me) << '\n';

  Person you(std::cin);
  print(std::cout, you) << '\n';
}