// Rewrite the first exercise to use a lambda in place of the end_connection
// function

#include <iostream>
#include <memory>
#include <string>

struct destination
{
  std::string address;
};

struct connection
{
  std::string address;
  bool connected;

  void print()
  {
    std::cout << "connection:\n\t" << address << ": "
              << (connected ? "" : "not ") << "connected\n";
  };
};

connection connect(destination *d) { return {d->address, true}; };

void disconnect(connection &p)
{
  p.address = "";
  p.connected = false;
};

int main()
{
  connection c;
  c.print();
  {
    destination d{"localhost"};

    c = connect(&d);
    c.print();

    std::shared_ptr<connection> p(&c, [](connection *c) { disconnect(*c); });
  }
  c.print();
}
