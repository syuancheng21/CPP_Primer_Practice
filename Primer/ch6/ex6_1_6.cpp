#include <iostream>

int sum_add(int n) {
    static int sum = 0;
    sum += n;
    return ++sum;
}

int main() {

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << sum_add(i) << std::endl;
    }
    

    return 0;
}