#ifndef BD265F35_6C5A_493F_B66E_0F683DDBF838
#define BD265F35_6C5A_493F_B66E_0F683DDBF838

#include <cstddef>
#include <iostream>
#include <string>

class Quote {
public:
  Quote() = default;
  Quote(const std::string &book, double price) : bookNo(book), price(price) {}

  std::string isbn() const { return bookNo; }

  virtual double net_price(std::size_t n) const { return n * price; }

  virtual void debug() const {
    std::cout << "data members of this class:\n"
              << "bookNo= " << this->bookNo << " "
              << "price= " << this->price << " ";
  }
  virtual ~Quote() = default;

private:
  std::string bookNo;

protected:
  double price = 0.0;
};

#endif /* BD265F35_6C5A_493F_B66E_0F683DDBF838 */
