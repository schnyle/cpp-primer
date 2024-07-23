// Add appropriate constructors to your Person class.

#include <iostream>
#include <string>

struct Person;
std::istream &read(std::istream &, Person &);

struct Person
{
  Person() = default;
  Person(const std::string &name, const std::string &addr) 
    : name(name), address(addr) { }
  Person(std::istream &is) { read(is, *this); }
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
  Person who;
  print(std::cout, who) << '\n';

  Person me("Kyle", "Denver");
  print(std::cout, me) << '\n';

  Person you(std::cin);
  print(std::cout, you) << '\n';  
}