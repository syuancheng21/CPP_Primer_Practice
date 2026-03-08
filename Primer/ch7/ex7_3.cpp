//
//ex7_3.h
// Exercise 7.3, P233
//

#include <iostream>
#include "ex7_2.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main() {
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (total.isdn() == trans.isdn())
            {
                total = total.combine(trans);
            } else {
                cout << "isdn: " << total.isdn() << ", units sold: " << total.units_sold
                << ", revenue: " << total.revenue << endl;
                total = trans;
            }
            
        }
        cout << "isdn: " << total.isdn() << ", units sold: " << total.units_sold
                << ", revenue: " << total.revenue << endl;
        
    } else {
        cout << "Input data failed" << endl;
        return -1;
    }
    

    return 0;
}