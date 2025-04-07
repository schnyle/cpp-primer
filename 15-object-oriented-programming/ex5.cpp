// Define your own version of the Bulk_quote class.

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

class Bulk_quote : public Quote
{
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &bn, const double p, const size_t mq,
             const double d)
      : Quote(bn, p), min_qty(mq), discount(d) {};

  double net_price(size_t n) const override
  {
    if (n >= min_qty)
    {
      return n * price * (1 - discount);
    }
    else
    {
      return n * price;
    };
  }

private:
  size_t min_qty = 0;
  double discount = 0.0;
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
  Bulk_quote cpp_primer_bulk("34-2346", 49.99, 5, 0.10);

  print_total(std::cout, cpp_primer, 5);
  print_total(std::cout, cpp_primer_bulk, 5);
}