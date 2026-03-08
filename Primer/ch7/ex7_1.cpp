//
//ex7_1.cpp
// Exercise 7.1, P230
// 输入： AAA BB C  DD

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


int main() {
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (total.bookNo == trans.bookNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                cout << "bookNo: " << total.bookNo << ", units sold: " << total.units_sold
                << ", revenue: " << total.revenue << endl;
                total = trans;
            }
            
        }
        cout << "bookNo: " << total.bookNo << ", units sold: " << total.units_sold
                << ", revenue: " << total.revenue << endl;
        
    } else {
        cout << "Input data failed" << endl;
        return -1;
    }
    

    return 0;
}