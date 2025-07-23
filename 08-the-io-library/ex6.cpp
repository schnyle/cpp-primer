// Rewrite the bookstore program from section 7.1.1 to read its transactions
// from a file. Pass the name of the file as an argument to main.

#include <iostream>
#include <fstream>
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

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Error: must have one file name input." << std::endl; 
  }

  std::string input_file_name = argv[1];
  std::ifstream input_file(input_file_name);

  Sales_data total;
  if (read(input_file, total))
  {
    Sales_data trans;
    while (read(input_file, trans))
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