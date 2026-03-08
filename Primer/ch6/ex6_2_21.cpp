#include <iostream>

using namespace std;

int return_max(const int a, const int *b) {
    return a > *b ? a : *b;
}

int main() {
    int a = 5, b = 3;

    std::cout << return_max(a, &b) << endl;

    return 0;
}