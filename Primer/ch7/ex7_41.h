#ifndef SYUAN_EX7_41_H
#define SYUAN_EX7_41_H

#include <string>
#include <iostream>

class Sales_data {
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    
public:
    Sales_data(const std::string& str, unsigned u, double p): bookNo(str), units_sold(u), revenue(u*p) {
        std::cout << "Sales_data(const std::string&, unsigned, double)" << std::endl;
    }
    Sales_data(): Sales_data("", 0, 0.0f) {
        std::cout << "Sales_data()" << std::endl;
    };
    Sales_data(const std::string& s): Sales_data(s, 0, 0.0f) {
        std::cout << "Sales_data(const std::string&)" << std::endl;
    }
    Sales_data(std::istream& is);

    std::string isdn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    inline double avg_price() const;
};

inline double Sales_data::avg_price() const {
    return units_sold ? revenue/units_sold : 0;
}


#endif // SYUAN_EX7_41_H