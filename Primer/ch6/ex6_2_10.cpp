#include <iostream>

void exchange_value(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 2, b = 3;
    exchange_value(&a, &b);
    std::cout << "a=" << a << " , b=" << b << std::endl;

    return 0;
}