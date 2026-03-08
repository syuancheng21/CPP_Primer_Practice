#include "chapter6.h"

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

int abs(int val) {
    
    return val > 0 ? val : -val;
}