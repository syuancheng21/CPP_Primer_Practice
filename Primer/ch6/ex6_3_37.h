#ifndef SYUAN_EX6_3_37_H
#define SYUAN_EX6_3_37_H

#include <string>
using std::string;

using ArrT = string[10];
ArrT& func1(ArrT& arr);

auto func2(ArrT& arr) -> string(&)[10];

string arrS[10];
decltype(arrS)& func3(ArrT& arr);


#endif // SYUAN_EX6_3_37_H