#include <iostream>

void reset(int* val) {
    *val = 0;
}

void reset(int& val) {
    val = 0;
}

void reset(const int& val) {
    
}

void exchange_value(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 3;
    reset(a);
    std::cout << a << std::endl;

    int m = 7, n = 10;
    reset(3);
    exchange_value(m, n);
    std::cout << "m=" << m << " , n=" << n << std::endl;
    return 0;
}