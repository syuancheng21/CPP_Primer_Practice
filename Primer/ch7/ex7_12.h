#ifndef SYUAN_EX7_11_H
#define SYUAN_EX7_11_H

#include <string>
#include <istream>
#include <ostream>

struct Sales_data; //TODO: why?
std::istream &read(std::istream&, Sales_data&);


struct Sales_data
{
    //constructor
    Sales_data() = default;
    Sales_data(const std::string& s): bookNo(s) {}
    Sales_data(const std::string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream &is) {read(is, *this);}

    std::string isdn() const { return bookNo; }
    Sales_data& combine(const Sales_data& rhs);
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream& read(std::istream& is, Sales_data& item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;

    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item) {
    os << "ISDN: " << item.isdn() << ", Sold Count: " << item.units_sold << ", Revenue: " << item.revenue;
    return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum; //sum是局部变量，但是我们返回的是值拷贝
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

double Sales_data::avg_price() const {
    return revenue/units_sold;
}


#endif // SYUAN_EX7_11_H