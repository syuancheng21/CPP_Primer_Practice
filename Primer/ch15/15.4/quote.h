#ifndef E65927D9_8B2C_4C26_9591_2E937780EB78
#define E65927D9_8B2C_4C26_9591_2E937780EB78

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

#endif /* E65927D9_8B2C_4C26_9591_2E937780EB78 */
