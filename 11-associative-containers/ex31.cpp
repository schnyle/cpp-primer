// Write a program that defines a multimap of authors and their works. Use find
// to find an element in the multimap and erase that element. Be sure your
// program works correctly if the element you look for is not in the map.

#include <iostream>
#include <map>
#include <string>

int main()
{
  std::multimap<std::string, std::string> author_works{{"Abe", "Abe's Book"},
                                                       {"Dabe", "Dabe's book"}};
  
  std::string book1("Gabe");
  if (auto it = author_works.find(book1); it != author_works.cend())
  {
    author_works.erase(it);
  }

  std::string book2("Abe");
  if (auto it = author_works.find(book2); it != author_works.cend())
  {
    author_works.erase(it);
  }

  for (auto  &p : author_works)
  {
    std::cout << p.first << ": " << p.second << "\n";
  }
}