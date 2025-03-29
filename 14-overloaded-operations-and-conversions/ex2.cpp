// Write declarations for the overloaded input, output, addition, and
// compund-assignment operators for Sales_data.

#include <iostream>
#include <string>

struct Sales_data
{
public:
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

std::istream &operator>>(std::istream &is, Sales_data &x) { return is; }

std::ostream &operator<<(std::ostream &os, const Sales_data &x) { return os; }

int main() {}