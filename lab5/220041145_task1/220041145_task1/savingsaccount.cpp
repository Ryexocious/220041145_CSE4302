#include "savingsaccount.h"
SavingsAccount::SavingsAccount(string name, string addr, double interestRate, double balance) {
    accname = name;
    address = addr;
    annualInterestRate = interestRate;
    currentBalance = balance;
    minBalance = balance;
}

void SavingsAccount::setAccName(string s) {
    accname = s;
}

void SavingsAccount::setAddress(string x) {
    address = x;
}

void SavingsAccount::setAnnualInterestRate(double k) {
    annualInterestRate = k;
}

void SavingsAccount::setCurrentBalance(double x) {
    currentBalance = x;
}

string SavingsAccount::getAccName() const {
    return accname;
}

string SavingsAccount::getAddress() const {
    return address;
}

double SavingsAccount::getAnnualInterestRate() const {
    return annualInterestRate;
}

double SavingsAccount::getCurrentBalance() const {
    return currentBalance;
}

void SavingsAccount::deposit(double amount) {
    currentBalance += amount;
    if (currentBalance < minBalance) {
        minBalance = currentBalance;
    }
}

bool SavingsAccount::withdraw(double amount) {
    if (amount <= currentBalance) {
        currentBalance -= amount;
        if (currentBalance < minBalance) {
            minBalance = currentBalance;
        }
        return true;
    }
    return false;
}
double SavingsAccount::calculateInterest(int periodInMonths) const {
    double monthlyInterestRate = (annualInterestRate / 12.0) / 100.0;
    return minBalance * monthlyInterestRate * periodInMonths;
}
void SavingsAccount::disburseInterest(int periodInMonths) {
    double interest = calculateInterest(periodInMonths);
    deposit(interest);
    minBalance = currentBalance;
}
