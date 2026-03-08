//
//ex7_2.h
// Exercise 7.2, P233
// 

#ifndef SYUAN_EX7_2_H
#define SYUAN_EX7_2_H

#include <iostream>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    std::string isdn() const { return bookNo; }
    Sales_data& combine(const Sales_data& rhs);
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}


#endif // SYUAN_EX7_2_H