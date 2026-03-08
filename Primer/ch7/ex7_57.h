#ifndef SYUAN_EX7_57_H
#define SYUAN_EX7_57_H

#include <string>
#include <iostream>

class Account
{
private:
    std::string owner;
    double amount;
    static double interestRate;
    static const double todayRate = 43.43;
    static double initRate() { return todayRate; }
public:
    Account()=default;
    Account(const std::string& name, double count): owner(name), amount(count) {
        std::cout << "Run list constructor!" << std::endl;
    }

    void calculate() { amount += amount*interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }
};

double Account::interestRate = initRate();


#endif // SYUAN_EX7_57_H