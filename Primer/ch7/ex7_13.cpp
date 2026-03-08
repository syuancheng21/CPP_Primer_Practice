//
//  ex7_13.cpp
//  Exercise 7.13
//
//  Created by pezy on 11/9/14.
//

#include "ex7_12.h"
#include <iostream>

int main() {
    Sales_data total(std::cin);
    if (!total.isdn().empty())
    {
        std::istream& is = std::cin;
        while (is)
        {
            Sales_data trans(is);
            if (!is)
            {
                break;
            }
            
            if (total.isdn() == trans.isdn())
            {
                total.combine(trans);
            } else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    } else {
        std::cout << "Read failed" << std::endl; 
        return -1;
    }
    
    return 0;
}