#include "ex7_11.h"
#include <iostream>

int main() {
    Sales_data item1;
    print(std::cout, item1) << std::endl;

    Sales_data item2("民国那些事");
    print(std::cout, item2)<< std::endl;

    Sales_data item3("亲密关系", 6, 27.0);
    print(std::cout, item3)<< std::endl;

    Sales_data item4(std::cin);
    print(std::cout, item4)<< std::endl;


    return 0;
}