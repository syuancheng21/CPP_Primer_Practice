#include <iostream>

void print(const int& n) {
    std::cout << n << std::endl;
}

void print(const int* p) {
    std::cout << *p << std::endl;
}

void print(const int* beg, const int* end) {
    while (beg != end)
    {
        std::cout << *beg++ << std::endl;
    }
}

void print(const int arr[], size_t s) {
    for (size_t i = 0; i < s; i++)
    {
        std::cout << arr[i] << std::endl;
    }  
}

void print(int (&arr)[2]) {
    for (auto i : arr)
    {
        std::cout << i << std::endl;
    }
}

int main() {
    int i = 0, j[2] = {3,1};
    print(i);
    print(j);

    return 0;
}