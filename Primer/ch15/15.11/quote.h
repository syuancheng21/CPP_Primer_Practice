#ifndef E3DF5D34_0F68_4D59_B6F2_4B9B6375FCB8
#define E3DF5D34_0F68_4D59_B6F2_4B9B6375FCB8

#include <iostream>
#include <string>

class Quote {
public:
  Quote() = default;
  Quote(std::string s, double p) : bookNo(s), price(p) {}

  std::string isbn() const { return bookNo; }

  virtual double net_price(size_t s) const;
  virtual void debug() const;

  virtual ~Quote() = default;

private:
  std::string bookNo;

protected:
  double price = 0.0;
};

double Quote::net_price(size_t s) const { return s * price; }

void Quote::debug() const {
  std::cout << "data members of this class:\n"
            << "bookNo= " << this->bookNo << " "
            << "price= " << this->price << " ";
}

#endif /* E3DF5D34_0F68_4D59_B6F2_4B9B6375FCB8 */
