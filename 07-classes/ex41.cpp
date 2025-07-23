// Rewrite your own version of the Sales_data class to use delegating
// constructors. Add a statement to the body of each of the constructors that
// prints a message whenever it is executed. Write declarations to construct a
// Sales_data object in every way possible. Study the output until you are
// certain you understand the order of execution among delegating constructors.

#include <iostream>
#include <string>

class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data
{
  friend std::ostream &print(std::ostream &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);

public:
  Sales_data(std::string s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(price) { std::cout << "constructor 0\n"; }
  Sales_data() : Sales_data("", 0, 0) { std::cout << "constructor 1\n"; }
  Sales_data(std::string s) : Sales_data(s, 0, 0) { std::cout << "constructor 2\n"; }
  Sales_data(std::istream &is) : Sales_data()
  {
    std::cout << "constructor 3\n";
    read(std::cin, *this);
  }
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &trans);
  double avg_price() const;

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
     << ", revenue: " << x.revenue << " avg price: " << x.avg_price() << "}";
  return os;
}

std::istream &read(std::istream &is, Sales_data &x)
{
  double price = 0;
  is >> x.bookNo >> x.units_sold >> price;
  x.revenue = x.units_sold * price;
  return is;
}

inline double Sales_data::avg_price() const
{
  if (units_sold == 0.0)
    return 0.0;
  return revenue / units_sold;
}

int main()
{
  std::cout << "sd1\n";
  Sales_data sd1("book1", 100, 234.34);
  std::cout << "sd2\n";
  Sales_data sd2;
  std::cout << "sd3\n";
  Sales_data sd3("book3");
  std::cout << "sd4\n";
  Sales_data sd4(std::cin);
}

// int main()
// {
//   Sales_data total(std::cin);
//   if (!std::cin)
//   {
//     std::cerr << "No data.\n";
//     return -1;
//   }

//   while (true)
//   {
//     Sales_data trans(std::cin);
//     if (!std::cin)
//     {
//       break;
//     }

//     if (total.isbn() == trans.isbn())
//       total.combine(trans);
//     else
//     {
//       print(std::cout, total) << '\n';
//       total = trans;
//     }
//   }
//   print(std::cout, total) << '\n';

//   return 0;
// }