// ex2: Add the combine and isbn members to the Sales_data class you wrote for
//      exercises in 2.6.2.
// ex3: Revise your transaction-processing program from 7.1.1 to use these
//      members.

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

void print_sales_data(Sales_data &x)
{
  std::cout << "{isbn: " << x.bookNo << ", sold: " << x.units_sold
            << ", revenue: " << x.revenue << "}\n";
}

std::istream &read(std::istream &is, Sales_data &x)
{
  is >> x.bookNo >> x.units_sold >> x.revenue;
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
        print_sales_data(total);
        total = trans;
      }
    }
    print_sales_data(total);
  }
  else
  {
    std::cerr << "No data\n";
  }

  return 0;
}