// Define your own versions of Disc_quote and Bulk_quote

#include <iostream>
#include <string>

class Quote
{
public:
  Quote() = default;
  Quote(const std::string &bn, const double p) : bookNo(bn), price(p) {}

  std::string isbn() const { return bookNo; }
  virtual double net_price(size_t n) const { return n * price; }
  virtual std::ostream &debug(std::ostream &os) const
  {
    os << "bookNo: " << bookNo << ", price: " << price;
    return os;
  }

  virtual ~Quote() = default;

private:
  std::string bookNo;

protected:
  double price = 0.0;
};

class Disc_quote : public Quote
{
public:
  Disc_quote() = default;
  Disc_quote(const std::string &bn, const double p, const size_t q,
             const double d)
      : Quote(bn, p), qty(q), discount(d)
  {
  }

  double net_price(size_t n) const = 0;

protected:
  size_t qty;
  double discount;
};

class Bulk_quote : public Disc_quote
{
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &bn, const double p, const size_t mq,
             const double d)
      : Disc_quote(bn, p, mq, d) {};

  double net_price(size_t n) const override
  {
    if (n >= qty)
    {
      return n * price * (1 - discount);
    }
    else
    {
      return n * price;
    };
  }

  std::ostream &debug(std::ostream &os) const override
  {
    os << "bookNo: " << isbn() << ", price: " << price << ", min_qty: " << qty
       << ", discount: " << discount;
    return os;
  }
};

class Limited_quote : public Quote
{
public:
  Limited_quote() = default;
  Limited_quote(const std::string &bn, const double p, const size_t mq,
                const double d)
      : Quote(bn, p), max_qty(mq), discount(d) {};

  double net_price(size_t n) const override
  {
    if (n > max_qty)
    {
      double discounted = max_qty * price * (1 - discount);
      double standard = (n - max_qty) * price;
      return discounted + standard;
    }
    else
    {
      return n * price * (1 - discount);
    }
  };

  std::ostream &debug(std::ostream &os) const override
  {
    os << "bookNo: " << isbn() << ", price: " << price
       << ", max_qty: " << max_qty << ", discount: " << discount;
    return os;
  }

private:
  size_t max_qty = 0;
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
  Quote cpp_primer("34-2346", 50.0);
  Bulk_quote cpp_primer_bulk("34-2346", 50.0, 5, 0.10);
  Limited_quote cpp_primer_limited("34-2346", 50.0, 3, 0.10);

  print_total(std::cout, cpp_primer, 5);
  cpp_primer.debug(std::cout) << "\n";

  print_total(std::cout, cpp_primer_bulk, 5);
  cpp_primer_bulk.debug(std::cout) << "\n";

  print_total(std::cout, cpp_primer_limited, 5);
  cpp_primer_limited.debug(std::cout) << "\n";
}