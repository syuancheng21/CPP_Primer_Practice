

#include "ex7_27.h"
#include <iostream>

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(std::cout);

    std::cout << "\n";

    myScreen.display(std::cout);

    std::cout << "\n";

    const Screen blank(5,5, 'z');
    blank.display(std::cout);

    return 0;
}