// Update your Sales_data class to hide its implementation. The programs you've
// written to use Sales_data operations should still continue to work.
// Recompile those programs with your new class definition to verify they still
// work.

#include <iostream>
#include <string>

class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data
{
  friend std::ostream &print(std::ostream &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);

public:
  Sales_data() = default;
  Sales_data(std::istream &is) { read(std::cin, *this); }
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &trans);

private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
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
  Sales_data total(std::cin);
  if (!std::cin)
  {
    std::cerr << "No data.\n";
    return -1;
  }

  while (true)
  {
    Sales_data trans(std::cin);
    if (!std::cin)
    {
      break;
    }

    if (total.isbn() == trans.isbn())
      total.combine(trans);
    else
    {
      print(std::cout, total) << '\n';
      total = trans;
    }
  }
  print(std::cout, total) << '\n';

  return 0;
}