// Write your own version of the Account class.

#include <iostream>
#include <string>

double INTEREST_RATE = 0.05;

class Account
{
  friend std::ostream &print(std::ostream &, const Account&);

public:
  Account(std::string s, double amt) : owner(s), amount(amt) {}

  void calculate() { amount += amount * interestRate; }
  static double rate() { return interestRate; }
  static void rate(double);
private:
  std::string owner;
  double amount;
  static double interestRate;
  static double initRate();
};

double Account::initRate()
{
  return INTEREST_RATE;
}

double Account::interestRate = initRate();

void Account::rate(double newRate)
{
  Account::interestRate = newRate;
}

std::ostream &print(std::ostream &os, const Account &acc)
{
  os << "{owner: " << acc.owner << ", amount: " << acc.amount << ", rate: " << Account::interestRate << "}\n";
  return os;
}

int main()
{
  Account myAccount("Kyle", 2013.47);
  print(std::cout, myAccount);
  myAccount.calculate();
  print(std::cout, myAccount);
  myAccount.rate(4.00);
  myAccount.calculate();
  print(std::cout, myAccount);
}