#include "iostream"

using namespace std;

int main() {
  int a = 0, b = 1;


  
  int *pa = &a, *pb = &b;

  cout << *pa << " " << *pb << endl;

  // change the value of a pointer
  pa = &b;

  // change the value of to which the pointer points
  *pb = a;

  cout << *pa << " " << *pb << endl;

  return 0;
}