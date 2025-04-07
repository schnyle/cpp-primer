// Define your own versions of the Quote class and the print_total function.

#include <iostream>
#include <string>

class Quote
{
public:
  Quote() = default;
  Quote(const std::string &bn, const double p) : bookNo(bn), price(p) {}

  std::string isbn() const { return bookNo; }
  virtual double net_price(size_t n) const { return n * price; }

  virtual ~Quote() = default;

private:
  std::string bookNo;

protected:
  double price = 0.0;
};

double print_total(std::ostream &os, Quote &item, size_t n)
{
  double res = item.net_price(n);
  os << "ISBN: " << item.isbn() << ", # sold: " << n << ", total due: " << res
     << "\n";
  return res;
};

int main()
{
  Quote cpp_primer("34-2346", 49.99);
  print_total(std::cout, cpp_primer, 5);
}