// Define an input operator for your Sales_data class

#include <iostream>
#include <sstream>
#include <string>

struct Sales_data
{
  friend std::ostream &operator<<(std::ostream &, const Sales_data &);
  friend std::istream &operator>>(std::istream &, Sales_data &);

public:
  Sales_data() = default;
  Sales_data(const std::string &bn) : bookNo(bn) {}
  Sales_data(const std::string &bn, unsigned us, double r)
      : bookNo(bn), units_sold(us), revenue(r)
  {
  }

  std::string isbn() const { return bookNo; }
  double avg_price() const;

  Sales_data operator+(const Sales_data &) const;
  Sales_data &operator+=(const Sales_data &);
  Sales_data &operator-=(const Sales_data &);
  Sales_data &operator*=(const Sales_data &);
  Sales_data &operator/=(const Sales_data &);

private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

double Sales_data::avg_price() const
{
  if (units_sold != 0)
  {
    return revenue / units_sold;
  }
  else
  {
    return 0;
  }
}

std::ostream &operator<<(std::ostream &os, const Sales_data &sd)
{
  os << sd.isbn() << " " << sd.units_sold << " " << sd.revenue << " "
     << sd.avg_price();
  return os;
}

std::istream &operator>>(std::istream &is, Sales_data &sd)
{
  double price;
  is >> sd.bookNo >> sd.units_sold >> price;
  if (is)
  {
    sd.revenue = sd.units_sold * price;
  }
  else
  {
    sd = Sales_data();
  }
  return is;
}

int main()
{
  std::string input1 = "0-201 10 24.95";
  std::string input2 = "10 24.95 0-201-99999-9";

  std::stringstream ss(input2);
  Sales_data sd;
  ss >> sd;
  std::cout << sd << std::endl;
}