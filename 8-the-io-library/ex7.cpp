// Revise the bookstore program from the previous section to write its output
// to a file. Pass the name of that file as a second argument to main.

#include <iostream>
#include <fstream>
#include <string>

struct Sales_data
{
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

std::ostream& print_sales_data(std::ostream & os, Sales_data &x)
{
  os << "{isbn: " << x.bookNo << ", sold: " << x.units_sold
            << ", revenue: " << x.revenue << "}\n";
  return os;
}

std::istream &read(std::istream &is, Sales_data &x)
{
  is >> x.bookNo >> x.units_sold >> x.revenue;
  return is;
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    std::cerr << "Error: must have two input file names (i/o)." << std::endl; 
  }

  std::string input_file_name = argv[1];
  std::ifstream input_file(input_file_name);

  std::string output_file_name = argv[2];
  std::ofstream output_file(output_file_name);

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
        print_sales_data(output_file, total);
        total = trans;
      }
    }
    print_sales_data(output_file, total);
  }
  else
  {
    std::cerr << "No data\n";
  }

  return 0;
}