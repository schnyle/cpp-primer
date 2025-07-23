// ex6: Define your own versions of the add, read, and print functions.
// ex7: Rewrite the transaction-processing program you wrote for the exercises
//      in 7.1.2 to use these new functions.

#include <iostream>
#include <string>

struct Sales_data
{
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &trans);
};

Sales_data &Sales_data::combine(const Sales_data &trans)
{
  units_sold += trans.units_sold;
  revenue += trans.revenue;
  return *this;
}

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
  Sales_data total;
  if (read(std::cin, total))
  {
    Sales_data trans;
    while (read(std::cin, trans))
    {
      if (total.isbn() == trans.isbn())
      {
        total.combine(trans);
      }
      else
      {
        print(std::cout, total);
        std::cout << '\n';
        total = trans;
      }
    }
    print(std::cout, total);
    std::cout << '\n';
  }
  else
  {
    std::cerr << "No data\n";
  }

  return 0;
}