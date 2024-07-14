#include <iostream>
#include "Sales_data.h"

void print_sales_data(Sales_data x)
{
  std::cout << '{'
            << x.bookNo << ", "
            << x.units_sold << ", "
            << x.revenue << "}\n";
}

void read_sales_data(Sales_data &x)
{
  std::cin >> x.bookNo >> x.units_sold >> x.revenue;
}

Sales_data sum_sales_data(Sales_data x1, Sales_data x2)
{
  if (x1.bookNo != x2.bookNo)
  {
    std::cerr << "Book ISBN's are not the same.\n";
    return x1;
  }

  Sales_data res;
  res.bookNo = x1.bookNo;
  res.units_sold = x1.units_sold + x2.units_sold;
  res.revenue = x1.revenue + x2.revenue;
  return res;
}

int main()
{
  // Sales_data sd;
  // read_sales_data(sd);
  // print_sales_data(sd);

  Sales_data sd1, sd2;
  read_sales_data(sd1);
  read_sales_data(sd2);
  Sales_data sum = sum_sales_data(sd1, sd2);
  print_sales_data(sum);


  return 0;
}