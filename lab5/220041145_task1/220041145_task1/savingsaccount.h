#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include<iostream>
#include<string>
using namespace std;

class SavingsAccount {
private:
    string accname;
    string address;
    double annualInterestRate;
    double currentBalance;
    double minBalance;

public:
    SavingsAccount(string name = "", string addr = "", double interestRate = 0, double balance = 0);
    void setAccName(string s);
    void setAddress(string x);
    void setAnnualInterestRate(double k);
    void setCurrentBalance(double x);
    string getAccName() const;
    string getAddress() const;
    double getAnnualInterestRate() const;
    double getCurrentBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);
    double calculateInterest(int periodInMonths) const;
    void disburseInterest(int periodInMonths);
};

#endif // SAVINGSACCOUNT_H


