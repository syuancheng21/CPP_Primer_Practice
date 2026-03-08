#include <iostream>

int count_call() {
    static int ctr = 0;

    return ++ctr > 1 ? 1 : 0;
}


int main() {

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << count_call() << std::endl;
    }

    return 0;
}