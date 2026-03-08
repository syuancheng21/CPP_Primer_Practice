#include <iostream>

using namespace std;

int abs(int val) {
    
    return val > 0 ? val : -val;
}


int main() {

    int s = abs(-5);

    cout << "abs is: " <<  s << endl;
}