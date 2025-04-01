// Which other arithmetic operators, if any, do you think Sales_data ought to
// support? Define any you think the class should include.

#include <iostream>
#include <sstream>
#include <string>

struct Sales_data
{
  friend std::ostream &operator<<(std::ostream &, const Sales_data &);
  friend std::istream &operator>>(std::istream &, Sales_data &);
  friend Sales_data operator+(const Sales_data &, const Sales_data &);
  friend Sales_data operator-(const Sales_data &, const Sales_data &);
  friend Sales_data operator*(const Sales_data &, const int);
  friend Sales_data operator*(const int, const Sales_data &);

public:
  Sales_data() = default;
  Sales_data(const std::string &bn) : bookNo(bn) {}
  Sales_data(const std::string &bn, unsigned us, double r)
      : bookNo(bn), units_sold(us), revenue(r)
  {
  }

  std::string isbn() const { return bookNo; }
  double avg_price() const;

  Sales_data &operator+=(const Sales_data &);
  Sales_data &operator-=(const Sales_data &);
  Sales_data &operator*=(const int);

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
  os << "isbn: " << sd.isbn() << ", units: " << sd.units_sold
     << ", rev: " << sd.revenue << ", price: " << sd.avg_price();
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

Sales_data &Sales_data::operator+=(const Sales_data &sd)
{
  if (this->bookNo != sd.bookNo)
  {
    std::cout << "Error: cannot add Sales_data items with different isbn";
    return *this;
  }

  this->units_sold += sd.units_sold;
  this->revenue += sd.revenue;
  return *this;
}

Sales_data &Sales_data::operator-=(const Sales_data &sd)
{
  if (this->bookNo != sd.bookNo)
  {
    std::cout << "Error: cannot subtract Sales_data items with different isbn";
    return *this;
  }

  this->units_sold -= sd.units_sold;
  this->revenue -= sd.revenue;
  return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data res = lhs;
  res += rhs;
  return res;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
  Sales_data res = lhs;
  res -= rhs;
  return res;
}

Sales_data &Sales_data::operator*=(const int mult)
{
  this->units_sold *= mult;
  this->revenue *= mult;
  return *this;
}

Sales_data operator*(const Sales_data &sd, const int mult)
{
  Sales_data res = sd;
  res *= mult;
  return res;
}

Sales_data operator*(const int mult, const Sales_data &sd) { return sd * mult; }

int main()
{
  std::string input1 = "0-201 10 24.95";
  std::string input2 = "0-201 5 9.99";

  std::stringstream ss1(input1);
  Sales_data sd1;
  ss1 >> sd1;

  std::stringstream ss2(input2);
  Sales_data sd2;
  ss2 >> sd2;

  std::cout << "sd1: " << sd1 << "\nsd2: " << sd2 << "\n";
  std::cout << "sd1 + sd2: " << sd1 + sd2 << "\n";
  sd1 += sd2;
  std::cout << "sd1 += sd2: " << sd1 << "\n";
  std::cout << "sd1: " << sd1 << "\nsd2: " << sd2 << "\n";
  std::cout << "sd1 * 3: " << sd1 * 3 << "\n";
  sd1 *= 3;
  std::cout << "sd1 *= 3: " << sd1 << "\n";
  std::cout << "sd1: " << sd1 << "\nsd2: " << sd2 << "\n";
}