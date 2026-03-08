#include <iostream>

int fact(int val) {
    int ret = 1;
    while (val > 1)
    {
        // ret = ret*val;
        // val--;
        ret *= val--;
    }

    return ret;
}


int main() {
    int val = 0;
    std::cout << "Please enter a num within [1, 13]: ";
    std::cin >> val;

    int s = fact(val);

    std::cout << "result is: " <<  s << std::endl;
}