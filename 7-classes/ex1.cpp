// Write a version of the transaction-processing program from 1.6 using the
// Sales_data class defined for the exercises in 2.6.1.

#include <iostream>
#include <string>

struct Sales_data
{
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

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
      if (total.bookNo == trans.bookNo)
      {
        total.revenue += trans.revenue;
        total.units_sold += trans.units_sold;
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