// Write your own version of a function that uses a shared_ptr to manage a
// connection.

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

void end_connection(connection *p) { disconnect(*p); };

int main()
{
  connection c;
  c.print();
  {
    destination d{"localhost"};

    c = connect(&d);
    c.print();

    std::shared_ptr<connection> p(&c, end_connection);
  }
  c.print();
}
