//
//ex7_7.cpp
// Exercise 7.7, P235
// 输入： AAA BB C  DD

#include "ex7_6.h"
#include <iostream>


int main() {
    Sales_data total;
    if (read(std::cin, total))
    {
        Sales_data trans;
        while (read(std::cin, trans))
        {
            if (total.isdn() == trans.isdn())
            {
                total = add(total, trans);
            } else {
                print(std::cout, total);
                total = trans;
            }
            
        }
        print(std::cout, total);
    } else {
        std::cout << "Input data failed" << std::endl;
        return -1;
    }
    


    return 0;
}