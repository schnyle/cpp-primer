// Define the Quote and Bulk_quote copy-control members to do the same job as
// the synthesized versions. Give them and the other constructors print
// statements that identify which function is running. Write programs using
// these classes and predict what objects will be created and destroyed. Compare
// your predictions with the output and continue experimenting until your
// predictions are reliably correct.

#include <iostream>
#include <string>

class Quote
{
public:
  Quote() = default;
  Quote(const std::string &bn, const double p) : bookNo(bn), price(p) {}
  Quote(const Quote &rhs)
  {
    std::cout << "Quote copy constructor\n";
    bookNo = rhs.bookNo;
    price = rhs.price;
  }
  Quote(Quote &&rhs)
  {
    std::cout << "Quote move constructor\n";
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
  }

  Quote &operator=(const Quote &rhs)
  {
    std::cout << "Quote copy assignment\n";
    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
  }
  Quote &operator=(Quote &&rhs)
  {
    std::cout << "Quote move assignment\n";
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
    return *this;
  }

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
  Bulk_quote(const Bulk_quote &bq) : Quote(bq)
  {
    std::cout << "Bulk_quote copy constructor\n";
    min_qty = bq.min_qty;
    discount = bq.discount;
  }
  Bulk_quote(Bulk_quote &&bq) : Quote(std::move(bq))
  {
    std::cout << "Bulk_quote move constructor\n";
    min_qty = std::move(bq.min_qty);
    discount = std::move(bq.discount);
  }

  Bulk_quote &operator=(const Bulk_quote &bq)
  {
    std::cout << "Bulk_quote copy assignment\n";
    Quote::operator=(bq);
    min_qty = bq.min_qty;
    discount = bq.discount;
    return *this;
  }
  Bulk_quote &operator=(Bulk_quote &&bq)
  {
    std::cout << "Bulk_quote move assignment\n";
    Quote::operator=(std::move(bq));
    min_qty = std::move(bq.min_qty);
    discount = std::move(bq.discount);
    return *this;
  }

  double net_price(size_t n) const override
  {
    if (n >= min_qty)
    {
      return n * price * (1 - discount);
    }
    else
    {
      return n * price;
    }
  }

private:
  size_t min_qty = 0;
  double discount = 0.0;
};

int main()
{
  Quote cpp_primer("34-2346", 49.99);
  Bulk_quote cpp_primer_bulk("34-2346", 49.99, 5, 0.10);

  // copy constructor
  std::cout << "1\n";
  Quote cpp_primer2(cpp_primer);

  std::cout << "2\n";
  Bulk_quote cpp_primer_bulk2(cpp_primer_bulk);

  // copy assignment
  std::cout << "3\n";
  Quote cpp_primer_3;
  cpp_primer_3 = cpp_primer;

  std::cout << "4\n";
  Bulk_quote cpp_primer_bulk3;
  cpp_primer_bulk3 = cpp_primer_bulk;

  // move constructor
  std::cout << "5\n";
  Quote cpp_primer_moved(std::move(Quote("98-7654", 29.99)));

  std::cout << "6\n";
  Bulk_quote cpp_primer_bulk_moved(
      std::move(Bulk_quote("98-7654", 29.99, 10, 0.15)));

  // move assignment operator
  std::cout << "7\n";
  cpp_primer2 = std::move(Quote("12-3456", 19.99));

  std::cout << "8\n";
  cpp_primer_bulk2 = std::move(Bulk_quote("12-3456", 19.99, 3, 0.05));
}