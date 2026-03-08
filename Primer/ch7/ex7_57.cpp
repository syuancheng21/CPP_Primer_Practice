#include "ex7_57.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {

    Account ac;
    cout << ac.rate() << endl;
    Account bc;
    cout << bc.rate() << endl;

    ac.rate(34.5);
    bc.rate(18.18);
    
    cout << ac.rate() << endl;
    cout << bc.rate() << endl;
    return 0;
}