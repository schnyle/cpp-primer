// Write a class that has three unsigned members representing year, month,
// and a day. Write a constructor that takes a string representing a date.
// Your constructor should handle a variety of date, formats, such as
// Januray 1, 1900, 1/1/1900, Jan 1, 1900, and so on.

// *** DNF *** //
 
#include <iostream>
#include <string>

const std::string months[]{"January", "February", "March", "April", "May", "June", "July", "Augst", "September", "October", "November", "December", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const std::string numeric = "0123456789";

class Date
{
private:
  int year, month, day;

public:
  Date(const std::string s) : year(), month(), day()
  {

    // long month names
    int count = 0;
    for (auto &m : months)
    {
      if (s.find(m) != std::string::npos)
      {
        year = (count % 12) + 1;
        break;
      }
      ++count;
    }

    // year = 1;
    // month = 2;
    // day = 3;
  }

  void print()
  {
    std::cout << year << "-" << month << "-" << day << "\n";
  }
};

int main()
{
  Date d1("July 24, 1999");
  d1.print();

  Date d2("24/7/1999");
  d2.print();

  Date d3("Aug 11, 1911");
  d3.print();
}