// Define an output operator for your Sales_data class

#include <iostream>
#include <string>

struct Sales_data
{
  friend std::ostream &operator<<(std::ostream &, const Sales_data &);

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

std::istream &operator>>(std::istream &is, Sales_data &x) { return is; }

std::ostream &operator<<(std::ostream &os, const Sales_data &sd)
{
  os << sd.isbn() << " " << sd.units_sold << " " << sd.revenue << " "
     << sd.avg_price();
  return os;
}

int main()
{
  Sales_data sd("yt7834vg", 6, 34.32);
  std::cout << sd << std::endl;
}