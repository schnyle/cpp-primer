// Add constructors to your Sales_data class and write a program to use each
// of the constructors.

#include <iostream>
#include <string>

struct Sales_data;
std::istream &read(std::istream &, Sales_data &);

struct Sales_data
{
  Sales_data() = default;
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}
  Sales_data(std::istream &is) { read(std::cin, *this); }
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &trans);
};

std::ostream &print(std::ostream &os, const Sales_data &x)
{
  os << "{isbn: " << x.bookNo << ", sold: " << x.units_sold
     << ", revenue: " << x.revenue << "}";
  return os;
}

std::istream &read(std::istream &is, Sales_data &x)
{
  double price = 0;
  is >> x.bookNo >> x.units_sold >> price;
  x.revenue = x.units_sold * price;
  return is;
}

int main()
{
  Sales_data sd1;
  print(std::cout, sd1);
  std::cout << '\n';

  Sales_data sd2("my book");
  print(std::cout, sd2);
  std::cout << '\n';

  Sales_data sd3("my new book", 42, 6.90);
  print(std::cout, sd3);
  std::cout << '\n';

  Sales_data sd4(std::cin);
  print(std::cout, sd4);
  std::cout << '\n';
}