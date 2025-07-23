// ex4: Write a class named Person that represents the name and address of a
//      person. Use a string to hold each of these elements. Subsequent
//      exercises will incrementally add features to this class.
// ex5: Provide operations in your Person class to return the name and
//      address. Should these fuctions be const? Explain.

#include <iostream>
#include <string>

struct Person
{
  std::string name;
  std::string address;
  std::string getName() const { return name; }
  std::string getAddress() const { return address; }
};

int main()
{
  Person me {"Kyle", "Denver"};
  std::cout << me.getName() << " " << me.getAddress() << "\n";
}